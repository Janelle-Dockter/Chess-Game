// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#include "Pawn.h"

using namespace std;

/**
 * Pawn implementation
 */

// Additional implementation will be added.

void Pawn::getMoveDescription()
{
    //
}

Square* Pawn::getMoveOptions()
{
    //
}

Square* Pawn::getMoveOptions(Square& location)
{
    //
}

string Pawn::getName()
{
    return "Pawn";
}

string Pawn::display()
{
    string value = getOwner().display();
    return (value + "P");
}


bool Pawn::canMoveTo(Square* location)
{
    bool retVal = false;

    // Handles white piece's move validity.
    if (getOwner().getColor() == 0)
    {
        if (getLocation()->getColumn() == location->getColumn())
        {
            if (getLocation()->getRow() == location->getRow() + 1)
            {
                if (!location->isOccupied())
                {
                    retVal = true;
                }
            }
            if (getLocation()->getRow() == location->getRow() + 2)
            {
                if (!hasMoved() && !location->isOccupied())
                {
                    retVal = true;
                }
            }
        }
        if (getLocation()->getColumn() - location->getColumn() == 1 ||
        getLocation()->getColumn() - location->getColumn() == -1)
        {
            if (getLocation()->getRow() - location->getRow() == 1)
            {
                if (location->isOccupied())
                {
                    retVal = true;
                }
            }
        }
    }

    // Handle's black piece's move validity.
    if (getOwner().getColor() == 1)
    {
        if (getLocation()->getColumn() == location->getColumn())
        {
            if (getLocation()->getRow() == location->getRow() - 1)
            {
                if (!location->isOccupied())
                {
                    retVal = true;
                }
            }
            if (getLocation()->getRow() == location->getRow() - 2)
            {
                if (!hasMoved() && !location->isOccupied())
                {
                    retVal = true;
                }
            }
        }
        if (getLocation()->getColumn() - location->getColumn() == 1 ||
            getLocation()->getColumn() - location->getColumn() == -1)
        {
            if (getLocation()->getRow() - location->getRow() == -1)
            {
                if (location->isOccupied())
                {
                    retVal = true;
                }
            }
        }
    }
    return retVal;
}
