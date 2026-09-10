// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#include "Rook.h"

/**
 * Rook implementation
 */

// Implementation will be added.

void Rook::getMoveDescription()
{
    //
}


Square* Rook::getMoveOptions()
{
    //
}


Square* Rook::getMoveOptions(Square& location)
{
    //
}

string Rook::getName()
{
    return "Rook";
}

bool Rook::canMoveTo(Square *location)
{
    return false;
}


string Rook::display()
{
    string value = getOwner().display();
    return (value + "R");
}
