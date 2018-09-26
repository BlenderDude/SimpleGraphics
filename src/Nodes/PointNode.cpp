//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include "PointNode.h"

PointNode::PointNode() : Node(1, 1) {
    // Set the only pixel to be the unicode box
    this->setPixel(0, 0, "\u25A0");
}