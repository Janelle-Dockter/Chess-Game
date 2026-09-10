// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06

using namespace std;

#include "Bishop.h"

/**
 * Bishop implementation
 */

// Implementation will be added later.

void Bishop::getMoveDescription()
{
    //
}


Square* Bishop::getMoveOptions()
{
    //
}


Square* Bishop::getMoveOptions(Square& location)
{
    //
}

string Bishop::getName()
{
    return "Bishop";
}

bool Bishop::canMoveTo(Square *location)
{
    return false;
}

string Bishop::display()
{
    string value = getOwner().display();
    return (value + "B");
}
