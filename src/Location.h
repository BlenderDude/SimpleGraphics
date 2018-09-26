//
// Created by Daniel Abdelsamed on 9/25/18.
//

#ifndef SIMPLEGRAPHICS_LOCATION_H
#define SIMPLEGRAPHICS_LOCATION_H

class Location {
private:
    int x = 0; // The horizontal position
    int y = 0; // The vertical position
public:
    Location(int x, int y);

    Location() = default;

    int getX() { return x; }

    void setX(int x) { this->x = x; }

    int getY() { return y; }

    void setY(int y) { this->y = y; }
};

#endif //SIMPLEGRAPHICS_LOCATION_H
