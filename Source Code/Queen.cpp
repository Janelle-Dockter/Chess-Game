#include "Queen.h"

using namespace std;

/**
 * Queen implementation
 */

// Additional implementation will be added later.

void Queen::getMoveDescription()
{
    //
}

Square* Queen::getMoveOptions()
{
    //
}

Square* Queen::getMoveOptions(Square& location)
{
    //
}

string Queen::getName()
{
    return "Queen";
}

bool Queen::canMoveTo(Square *location)
{
    bool canMoveTo = false;
    if (location != getLocation())
    {
        // Check if horizontal
        if (getLocation()->getRow() == location->getRow())
        {
            if (getOwner().getBoard()->canClearRow(location, getLocation()))
            {
                if (location->occupiedBy() != getColor())
                {
                    canMoveTo = true;
                }
            }
        }
        // Check if vertical
        else if (getLocation()->getColumn() == location->getColumn())
        {
            if (getOwner().getBoard()->canClearColumn(location, getLocation()))
            {
                if (location->occupiedBy() != getColor())
                {
                    canMoveTo = true;
                }
            }
        }
        else
        {
            int slope = (location->getRow() - getLocation()->getRow()) /
                    (location->getColumn() - getLocation()->getColumn());
            // Check if diagonal
            if (slope == 1 || slope == -1)
            {
                if (getOwner().getBoard()->canClearDiagonal(location, getLocation()))
                {
                    if (location->occupiedBy() != getColor())
                    {
                        canMoveTo = true;
                    }
                }
            }
        }

    }
    return canMoveTo;
}


string Queen::display()
{
    string value = getOwner().display();
    return (value + "Q");
}

