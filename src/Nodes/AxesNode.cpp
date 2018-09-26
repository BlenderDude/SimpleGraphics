//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include "AxesNode.h"

/**
 * Initialize an axes with a given size. This size represents the height of the graph.
 * @param parent
 * @param position
 * @param size
 */
AxesNode::AxesNode(short size) : Node(size * 2 + 1, size + 1) {
    short height = size + 1;
    // The width will be twice the height because the
    // height of a character in the terminal is approximately 2 times its width.
    short width = size * 2 + 1;

    // Use a nested for loop to iterate through each of the possible pixels and paint the axes using unicode characters
    for (short y = 0; y < height; y++) {
        for (short x = 0; x < width; x++) {
            if (y == height / 2 && x == width / 2) {
                // If the pixel being painted is in the center of the pixels, set as the plus
                this->setPixel(x, y, "\u254B");
            } else if (y == height / 2) {
                // If the y level being set is in the center, set as the horizontal lines
                if (x == 0) {
                    // If it is the left most pixel, set as the left cap
                    this->setPixel(x, y, "\u2523");
                } else if (x == width - 1) {
                    // If it is the right most pixel, set as the right cap
                    this->setPixel(x, y, "\u252B");
                } else {
                    // Otherwise just set as the horizontal bar
                    this->setPixel(x, y, "\u2501");
                }
            } else if (x == width / 2) {
                // If the x level being set is in the center, set as the vertical lines.
                if (y == 0) {
                    // If it is the upper most pixel, set as the top cap
                    this->setPixel(x, y, "\u2533");
                } else if (y == height - 1) {
                    // If it is the bottom most pixel, set as the bottom cap
                    this->setPixel(x, y, "\u253B");
                } else {
                    // Otherwise set as the vertical bar
                    this->setPixel(x, y, "\u2503");
                }
            }

            // All other pixels are left as empty by default
        }
    }
}