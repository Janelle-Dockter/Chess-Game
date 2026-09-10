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
    bool retVal = false;
    if (location != getLocation())
    {
        if (getLocation()->getRow() == location->getRow())
        {
            if (getOwner().getBoard()->canClearRow(location, getLocation()))
            {
                if (location->occupiedBy() != getColor())
                {
                    retVal = true;
                }
            }
        }
        else if (getLocation()->getColumn() == location->getColumn())
        {
            if (getOwner().getBoard()->canClearColumn(location, getLocation()))
            {
                if (location->occupiedBy() != getColor())
                {
                    retVal = true;
                }
            }
        }
    }
    return retVal;
}


string Rook::display()
{
    string value = getOwner().display();
    return (value + "R");
}
