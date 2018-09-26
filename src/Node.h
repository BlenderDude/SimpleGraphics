//
// Created by Daniel Abdelsamed on 9/25/18.
//

#ifndef SIMPLEGRAPHICS_NODE_H
#define SIMPLEGRAPHICS_NODE_H

#include "Location.h"
#include "Position.h"

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Node : public Location {
private:
    short width;
    short height;
    Node *parent = nullptr; // The parent node that has this node as a child
    vector<Node *> children; // All of the children that will paint over the node
    vector<vector<string>> pixels; // The pixels that represent the display
    Position *position = nullptr;

    void emptyPixelVectors(short width, short height) {
        pixels.clear(); // Clear out all of the existing pixel data

        // Iterate through each row and push a new vector to the row of pixels
        for (short row = 0; row < height; row++) {
            // Construct a vector with the initial size that equals the width of the node and fill it with spaces (empties)
            vector<string> rowVector(width, " ");

            // Push the emptied row vector onto the pixels vector
            pixels.push_back(rowVector);
        }
    }

public:
    Node(short width, short height);

    void calculatePosition(Position *position);

    void addChild(Node *child, Position *position);

    void setParent(Node *parent) { this->parent = parent; }

    Node *getParent() { return this->parent; }

    short getGlobalX();

    short getGlobalY();

    vector<Node *> getChildren() { return this->children; }

    void setPixel(short x, short y, string character);

    short getWidth() { return this->width; }

    short getHeight() { return this->height; }

    Position *getPosition() { return this->position; }

    string getPixel(int requestedX, int requestedY);

    void clear() { this->emptyPixelVectors(this->width, this->height); }
};


#endif //SIMPLEGRAPHICS_NODE_H
