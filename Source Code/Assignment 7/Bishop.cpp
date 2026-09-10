// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23

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

string Bishop::display()
{
    string value = getOwner().display();
    return (value + "B");
}
