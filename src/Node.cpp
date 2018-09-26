//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include "Location.h"
#include "Position.h"
#include "Node.h"

/**
  * Initialize the Node with a given width and height
  * @param width
  * @param height
  */
Node::Node(short width, short height) {
    // Set the width and the height from the arguments
    this->width = width;
    this->height = height;

    // Empty the pixels to set them up with the correct sized vectors and clear them
    this->emptyPixelVectors(width, height);
}

/**
  * Set a pixel to a certain "character"
  * @param x
  * @param y
  * @param character - string instead of char because of the needed support for unicode which is 4 bytes
  */
void Node::setPixel(short x, short y, string character) {
    this->pixels[y][x] = character;
}

void Node::calculatePosition(Position *position) {
    this->position = position;

    int x;

    // Switch against the HorizontalAlignment enum from the Position class to determine x position
    switch (position->getHorizontalAlignment()) {
        case Position::HorizontalAlignmentOption::ALIGN_LEFT:
            // If the alignment is to the left, the x relative to the parent is just the horizontal margin
            /*
             * |---- Parent Width ----|
             *      |-This Width-|
             * |-X-|
             *
             */
            x = position->getMargin(Position::MarginLocation::MARGIN_HORIZONTAL);
            break;
        case Position::HorizontalAlignmentOption::ALIGN_RIGHT:
            // If the alignment is to the right, the x relative to the parent is the width of the parent - the margin - the width of the child
            /*
             * |---- Parent Width ----|
             *           |-This Width-|
             * |--- X ---|
             *
             */
            x = parent->getWidth() - position->getMargin(Position::MarginLocation::MARGIN_HORIZONTAL) - width;
            break;
        case Position::HorizontalAlignmentOption::ALIGN_CENTER:
            // If the alignment is to the center, the x relative to the parent is the parents with - the child's then that divided by 2
            // The double is then rounded to the nearest integer (implicitly cast) because the terminal can not split a character
            /*
             * |---- Parent Width ----|
             * |-X-||-This Width-|
             *
             *
             */
            x = round((parent->getWidth() - width) / 2.0);
            break;
    }

    // Add the X offset at the end
    x += position->getXOffset();

    // Set the object's x position to the calculated value
    this->setX(x);


    /*
     *
     * Calculating the y value is identical to the x except for using the y axis and the vertical margins
     *
     * Refer to the x calculations for explanations
     *
     */

    int y;

    switch (position->getVerticalAlignment()) {
        case Position::VerticalAlignmentOption::ALIGN_TOP:
            y = position->getMargin(Position::MarginLocation::MARGIN_VERTICAL);
            break;
        case Position::VerticalAlignmentOption::ALIGN_BOTTOM:
            y = parent->getHeight() - position->getMargin(Position::MarginLocation::MARGIN_VERTICAL) - height;
            break;
        case Position::VerticalAlignmentOption::ALIGN_CENTER:
            y = round((parent->getHeight() - height) / 2.0);
            break;
    }

    y += position->getYOffset();

    this->setY(y);
}

void Node::addChild(Node *child, Position *position) {
    // Add the child to the vector of children
    this->children.push_back(child);
    // Set the of the child to this object
    child->setParent(this);
    // Re/calculate the position of the child in case the parent changed
    child->calculatePosition(position);
}

short Node::getGlobalX() {

    short x = this->getX();

    Node *parent = this->getParent();

    while (true) {
        if (parent == nullptr) {
            break;
        }

        x += parent->getX();

        parent = parent->getParent();
    }

    return x;
}

short Node::getGlobalY() {
    short y = this->getY();

    Node *parent = this->getParent();

    while (true) {
        if (parent == nullptr) {
            break;
        }

        y += parent->getX();

        parent = parent->getParent();
    }

    return y;
}

/**
 * Determine what a certain pixel should render based on the node itself and its children
 * @param requestedX
 * @param requestedY
 * @return pixel - what should be painted on that pixel
 */
string Node::getPixel(int requestedX, int requestedY) {

    if (this->position != nullptr) {
        this->calculatePosition(this->position);
    }

    // Adjust the requested coordinates for the position of the Node
    int x = requestedX - this->getX();
    int y = requestedY - this->getY();

    // Determine if the point is within the bounds of the node
    bool pointWithinBounds = !(x < 0 || x > this->width - 1 || y < 0 || y > this->height - 1);


    // Iterate through each child if there are any
    for (unsigned int i = 0; i != this->children.size(); i++) {
        Node *child = this->children[i];
        // Call get pixel on the children, the first child with a pixel that is non-empty (not a space) will get returned
        string pixel = child->getPixel(x, y); // Recurse through the children
        if (pixel != " ") {
            return pixel;
        }
    }

    // If no points are painted from the children, or if there are no children, determine if the point is within the bounds
    if (pointWithinBounds) {
        // If so, return whatever the pixel is from the node's pixel array
        return this->pixels[y][x];
    } else {
        // If not return an empty (space)
        return " ";
    }
}