//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include "TextNode.h"

/**
 * Create a text node with a given string and a position. TextNode extends Node and constructs the node
 * with the width equal to the length of the text and a height of 1.
 * @param parent
 * @param position
 * @param text
 */
TextNode::TextNode(string text) : Node(text.length(), 1) {

    // Iterate through the characters of the string
    for (unsigned short x = 0; x < text.length(); x++) {
        // Grab the character from that position in the text
        char character = text.at(x);

        // Set the pixel to be that character, constructing a string because set pixel requires a string
        this->setPixel(x, 0, string(1, character));
    }
}