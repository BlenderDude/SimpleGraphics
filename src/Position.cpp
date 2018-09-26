//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include "Position.h"

/**
  * Shorthand to ease initialization
  * @param horizontalAlignment
  * @param horizontalMargin
  * @param verticalAlignment
  * @param verticalMargin
  */
Position::Position(
        Position::HorizontalAlignmentOption horizontalAlignment,
        short horizontalMargin,
        Position::VerticalAlignmentOption verticalAlignment,
        short verticalMargin
) {
    this->setHorizontalAlignment(horizontalAlignment);
    this->setMargin(MarginLocation::MARGIN_HORIZONTAL, horizontalMargin);

    this->setVerticalAlignment(verticalAlignment);
    this->setMargin(MarginLocation::MARGIN_VERTICAL, verticalMargin);
}

/**
 * Shorthand to ease initialization
 * @param horizontalAlignment
 * @param horizontalMargin
 * @param verticalAlignment
 * @param verticalMargin
 * @param xOffset
 * @param yOffset
 */
Position::Position(
        Position::HorizontalAlignmentOption horizontalAlignment,
        short horizontalMargin,
        Position::VerticalAlignmentOption verticalAlignment,
        short verticalMargin,
        short xOffset,
        short yOffset
) {
    this->setHorizontalAlignment(horizontalAlignment);
    this->setMargin(MarginLocation::MARGIN_HORIZONTAL, horizontalMargin);

    this->setVerticalAlignment(verticalAlignment);
    this->setMargin(MarginLocation::MARGIN_VERTICAL, verticalMargin);

    this->setXOffset(xOffset);
    this->setYOffset(yOffset);
}

/**
 * Set the margin along a certain axis
 * @param marginLocation
 * @param margin
 */
void Position::setMargin(MarginLocation marginLocation, short margin) {
    switch (marginLocation) {
        case MarginLocation::MARGIN_HORIZONTAL:
            this->marginHorizontal = margin;
            break;
        case MarginLocation::MARGIN_VERTICAL:
            this->marginVertical = margin;
            break;
    }
}

/**
 * Get the margin along a certain axis
 * @param marginLocation
 * @return margin
 */
short Position::getMargin(MarginLocation marginLocation) {
    switch (marginLocation) {
        case MarginLocation::MARGIN_HORIZONTAL:
            return this->marginHorizontal;
        case MarginLocation::MARGIN_VERTICAL:
            return this->marginVertical;
    }
}