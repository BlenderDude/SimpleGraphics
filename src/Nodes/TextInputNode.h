//
// Created by Daniel Abdelsamed on 9/25/18.
//

#ifndef SIMPLEGRAPHICS_TEXTINPUTNODE_H
#define SIMPLEGRAPHICS_TEXTINPUTNODE_H

#import <string>
#include "../Node.h"

using namespace std;

class TextInputNode : public Node{
public:
    TextInputNode(string prompt);

    string getInput();
};


#endif //SIMPLEGRAPHICS_TEXTINPUTNODE_H
