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

bool Bishop::canMoveTo(Square* location)
{
    bool retVal = false;
    if (location != getLocation() && location->getColumn() != getLocation()->getColumn())
    {
        // Check if diagonal
        int slope = (location->getRow() - getLocation()->getRow()) / (location->getColumn() - getLocation()->getColumn());
        if (slope == 1 || slope == -1)
        {
            if (getOwner().getBoard()->canClearDiagonal(location, getLocation()))
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

string Bishop::display()
{
    string value = getOwner().display();
    return (value + "B");
}
