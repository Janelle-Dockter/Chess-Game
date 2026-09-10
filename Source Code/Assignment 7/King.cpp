// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#include "King.h"

using namespace std;

/**
 * King implementation
 */

// Other implementation will be added later.

bool King::isInCheck()
{
    return (getLocation() -> kingCanMoveHere(getColor()));
}

void King::getMoveDescription()
{
    //
}

Square* King::getMoveOptions()
{
    //
}

Square* King::getMoveOptions(Square& location)
{
    //
}

string King::display()
{
    string value = getOwner().display();
    return (value + "K");
}