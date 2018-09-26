//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include <sys/ioctl.h>
#include <iostream>

#include "src/Nodes/Grid.h"
#include "src/Nodes/TextInputNode.h"

using namespace std;

Grid createGrid() {

    int width = 100;
    int height = 25;

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    if (w.ws_col > 0) {
        width = w.ws_col;
    }

    if (w.ws_row > 0) {
        height = w.ws_row;
    }

    Grid grid(width, height);

    return grid;
}

int main() {

    Grid grid = createGrid();

    TextInputNode textInputNode("Test input: ");

    grid.addChild(&textInputNode, new Position(
            Position::HorizontalAlignmentOption::ALIGN_LEFT,
            4,
            Position::VerticalAlignmentOption::ALIGN_TOP,
            4
    ));

    grid.addBorder();

    grid.print();

    textInputNode.getInput();

    grid.print();

    return 0;
}