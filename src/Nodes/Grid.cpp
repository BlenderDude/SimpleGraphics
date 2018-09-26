//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include "Grid.h"

/**
 * checkSize is a funciton that makes sure the terminal window is wide enough to paint the canvas
 */
void Grid::checkSize() {
    // Store the instructions
    string instructions = " Please resize your terminal such that this bar fits on one line ";

    // Determine the amount of padding required in dashes to make the instructions centered.
    short paddingSize = (this->getWidth() - 2 - instructions.length()) / 2; // width - 2 to make room for the unicode caps

    // Print the left cap
    cout << "\u2523";

    // Print the left padding in horizontal bars
    for (short i = 0; i < paddingSize; i++) {
        cout << "\u2501";
    }

    // Print the instructions
    cout << instructions;

    // Print the right padding in horizontal bars
    for (short i = 0; i < paddingSize; i++) {
        cout << "\u2501";
    }

    // Print the right cap
    cout << "\u252B" << endl;

    // Print out the continuing instructions
    cout << endl << "Press enter to continue" << endl;

    // Wait for the next user input (an enter)
    cin.get();
}

/**
 * Add a border around the grid
 */
void Grid::addBorder() {
    // Assign local variables from the private ones
    int width = this->getWidth();
    int height = this->getHeight();

    // Iterate through each pixel and add a border on the edges
    for (short y = 0; y < height; y++) {
        for (short x = 0; x < width; x++) {
            if (x == 0 && y == 0) {
                this->setPixel(x, y, "\u250C"); // Top left corner
            } else if (x == 0 && y == height - 1) {
                this->setPixel(x, y, "\u2514"); // Bottom left corner
            } else if (x == width - 1 && y == 0) {
                this->setPixel(x, y, "\u2510"); // Top right corner
            } else if (x == width - 1 && y == height - 1) {
                this->setPixel(x, y, "\u2518"); // Bottom right corner
            } else if (x == 0 || x == width - 1) {
                this->setPixel(x, y, "\u2502"); // Vertical bars
            } else if (y == 0 || y == height - 1) {
                this->setPixel(x, y, "\u2500"); // Horizontal bars
            }
        }
    }
}

/**
 * Print out the grid to the console
 */
void Grid::print() {

    cout << "\033[1;0f " << flush;

    stringstream output;

    // For each pixel on the grid, determine what should be painted based on the pixel of the children
    for (int y = 0; y < this->getHeight(); y++) {
        for (int x = 0; x < this->getWidth(); x++) {
            // Paint a pixel
            output << getPixel(x, y);
        }
        // Create a new line to paint a new row
        if (y != this->getHeight() - 1) {
            output << endl;
        }

    }

    cout << "\b" << output.str() << flush;
}