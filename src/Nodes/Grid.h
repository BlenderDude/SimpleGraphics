//
// Created by Daniel Abdelsamed on 9/25/18.
//

#ifndef SIMPLEGRAPHICS_GRID_H
#define SIMPLEGRAPHICS_GRID_H

#include <iostream>
#include <sstream>
#include "../Node.h"

using namespace std;

class Grid : public Node {
public:
    /**
     * Initialize the Grid with a certain width and height and pass it along to the Node constructor
     * @param width
     * @param height
     */
    Grid(short width, short height) : Node(width, height) {}

    void checkSize();

    void addBorder();

    void print();
};


#endif //SIMPLEGRAPHICS_GRID_H
