//
// Created by Daniel Abdelsamed on 9/25/18.
//

#include "TextInputNode.h"
#include "TextNode.h"
#include "../Position.h"

#include <iostream>

TextInputNode::TextInputNode(string prompt) : Node(prompt.length(), 1) {
    TextNode *promptNode = new TextNode(prompt);

    this->addChild(promptNode, new Position());
}

string TextInputNode::getInput() {
    short globalX = this->getGlobalX();
    short globalY = this->getGlobalY();

    std::cout << "\033[" << globalY + 1 << ";" << globalX + this->getWidth() + 1 << "f" << std::flush;

    string input;

    std::cin >> input;

    TextNode *inputNode = new TextNode(input);

    Position *position = new Position();

    position->setXOffset(this->getWidth());

    this->addChild(inputNode, position);

    return input;
}