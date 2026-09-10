// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#include "Queen.h"

using namespace std;

/**
 * Queen implementation
 */

// Additional implementation will be added later.

void Queen::getMoveDescription()
{
    //
}

Square* Queen::getMoveOptions()
{
    //
}

Square* Queen::getMoveOptions(Square& location)
{
    //
}

string Queen::getName()
{
    return "Queen";
}

bool Queen::canMoveTo(Square *location)
{
    return false;
}


string Queen::display()
{
    string value = getOwner().display();
    return (value + "Q");
}

