// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


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
    bool canMoveTo = false;
    int vertDistance = getLocation()->getRow() - location->getRow();
    int horizontalDist = getLocation()->getColumn() - location->getColumn();
    bool vertValid = vertDistance == 0 || vertDistance == 1 || vertDistance == -1;
    bool horizontalValid = horizontalDist == 0 || horizontalDist == 1 || horizontalDist == -1;
    bool upper = vertDistance == 1;
    bool lower = vertDistance == -1;
    bool right = horizontalDist == -1;
    bool left = horizontalDist == 1;
    if (vertValid && horizontalValid)
    {
        if ((upper && right) || (upper && left))
        {
            canMoveTo = true;
        }
        else if ((lower && right) || (lower && left))
        {
            canMoveTo = true;
        }
        else if (upper || lower)
        {
            canMoveTo = true;
        }
        else if (right || left )
        {
            canMoveTo = true;
        }
        if (location->occupiedBy() == getColor())
        {
            canMoveTo = false;
        }
    }
    return canMoveTo;
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