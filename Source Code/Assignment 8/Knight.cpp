// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#include "Knight.h"

using namespace std;

/**
 * Knight implementation
 */

// Other implementation will be added later.

void Knight::getMoveDescription()
{
    //
}

Square* Knight::getMoveOptions()
{
    //
}

Square* Knight::getMoveOptions(Square& location)
{
    //
}

string Knight::getName()
{
    return "Knight";
}

bool Knight::canMoveTo(Square* location)
{
    return false;
}

string Knight::display()
{
    string value = getOwner().display();
    return (value + "N");
}

