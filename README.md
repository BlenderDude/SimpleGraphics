# Simple Graphics for C++

A simple 2D graphics library created out of Nodes. The basic node allows for anything, but there are some pre-generated classes to make integration simpler.

## Grid

The grid class is the master class that special functions to print all of its children to the screen. It can be initialized at any size, but the full console size is recommended for the best experience. This can be accomplished with the following code:

```

#include <sys/ioctl.h>

int width = GRID_WIDTH; // Fallbacks for if the console does not support rows and cols
int height = GRID_HEIGHT;

struct winsize w;
ioctl(0, TIOCGWINSZ, &w);

if (w.ws_col > 0) {
    width = w.ws_col;
}

if (w.ws_row > 0) {
    height = w.ws_row;
}

Grid grid(width, height);

```

## AxesNode

This node prints an axes to the screen. A point can then be placed as one of its children to allow for on-screen graphing

## PointNode

Points a single pixel to the screen

## TextNode

Prints a single line of text to the desired location on the screen