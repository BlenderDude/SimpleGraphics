//
// Created by Daniel Abdelsamed on 9/25/18.
//

#ifndef SIMPLEGRAPHICS_POSITION_H
#define SIMPLEGRAPHICS_POSITION_H

class Position {
public:
    // MarginLocation describes the possible values that can be changed for the margin
    enum class MarginLocation {
        MARGIN_HORIZONTAL,
        MARGIN_VERTICAL,
    };

    // NOTE vertical and horizontal alignment options are separate enums to allow for differing relations in the future

    // HorizontalAlignmentOption describes the possible relations that a node can have to its parent on the x axis
    enum class HorizontalAlignmentOption {
        ALIGN_LEFT,
        ALIGN_RIGHT,
        ALIGN_CENTER,
    };

    // VerticalAlignmentOption describes the possible relations that a node can have to its parent on the y axis
    enum class VerticalAlignmentOption {
        ALIGN_TOP,
        ALIGN_BOTTOM,
        ALIGN_CENTER,
    };

    /**
     * Initialize a position class with the default values
     */
    Position() {}


    Position(
            HorizontalAlignmentOption horizontalAlignment,
            short horizontalMargin,
            VerticalAlignmentOption verticalAlignment,
            short verticalMargin
    );

    Position(
            HorizontalAlignmentOption horizontalAlignment,
            short horizontalMargin,
            VerticalAlignmentOption verticalAlignment,
            short verticalMargin,
            short xOffset,
            short yOffset
    );


    void setHorizontalAlignment(HorizontalAlignmentOption horizontalAlignment) { this->horizontalAlignment = horizontalAlignment; }

    HorizontalAlignmentOption getHorizontalAlignment() { return this->horizontalAlignment;}


    void setVerticalAlignment(VerticalAlignmentOption verticalAlignment) { this->verticalAlignment = verticalAlignment; }

    VerticalAlignmentOption getVerticalAlignment() { return this->verticalAlignment; }

    void setMargin(MarginLocation marginLocation, short margin);

    short getMargin(MarginLocation marginLocation);

    void setXOffset(short xOffset) { this->xOffset = xOffset; }

    short getXOffset() { return this->xOffset; }

    void setYOffset(short yOffset) { this->yOffset = yOffset; }

    short getYOffset() { return this->yOffset; }

private:
    short xOffset = 0; // The x offset of the node against its calculated position
    short yOffset = 0; // The y offset fo the node against its calculated position
    short marginHorizontal = 0; // The horizontal margin against the x axis
    short marginVertical = 0; // The vertical margin against the y axis
    HorizontalAlignmentOption horizontalAlignment = HorizontalAlignmentOption::ALIGN_LEFT; // Default horizontal alignment to left
    VerticalAlignmentOption verticalAlignment = VerticalAlignmentOption::ALIGN_TOP; // Default vertical alignment to right
};

#endif //SIMPLEGRAPHICS_POSITION_H
