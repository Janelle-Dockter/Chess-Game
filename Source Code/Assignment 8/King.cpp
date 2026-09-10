// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


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

bool King::canMoveTo(Square* location)
{
    return false;
}

string King::getName()
{
    return "King";
}

string King::display()
{
    string value = getOwner().display();
    return (value + "K");
}