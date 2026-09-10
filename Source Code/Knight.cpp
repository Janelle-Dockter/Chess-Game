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
    bool canMoveTo = false;
    double slope = static_cast<double>(location->getRow() - getLocation()->getRow()) /
            (location->getColumn() - getLocation()->getColumn());
    if (slope == -0.5 || slope == 0.5)
    {
        if (location->occupiedBy() != getColor())
        {
            canMoveTo = true;
        }
    }
    if (slope == 2 || slope == -2)
    {
        if (location->occupiedBy() != getColor())
        {
            canMoveTo = true;
        }
    }
    return canMoveTo;
}

string Knight::display()
{
    string value = getOwner().display();
    return (value + "N");
}

