#include "Pawn.h"
#include "Board.h"

using namespace std;

/**
 * Pawn implementation
 */

// Additional implementation will be added.

bool Pawn::move(Square* location)
{
    // To handle En Passant, the pawn must be marked if it has just moved a special double jump.
    if(!hasMoved() && abs(location->getRow() - getLocation()->getRow()) == 2)
    {
        _justDoubleMoved = true;
    }
    // Handles typical move procedure (including determining if the move will put the player in check).
    bool canMove = true;
    Square* startingLocation = getLocation();
    Piece* startingOtherPiece = location->getOccupant();
    if (location->isOccupied())
    {
        location->getOccupant()->getCapturedByOpponent();
    }
    getLocation()->setOccupant(nullptr);
    setLocation(location);
    getLocation()->setOccupant(this);
    if (getOwner().getOpponent()->willPutInCheck(getOwner().getKing()->getLocation()))
    {
        canMove = false;
        setLocation(startingLocation);
        getLocation()->setOccupant(this);
        location->setOccupant(startingOtherPiece);
    }
    else
    {
        makeHasMoved();
        _justDoubleMoved = false;
        //getOwner().getBoard()->remove(startingOtherPiece);
    }
    // Handles extra pawn behavior like promotion.
    if (!hasBeenPromoted())
    {
        if ((getColor() == 0 && getLocation()->getRow() == 0) || (getColor() == 1 && getLocation()->getRow() == 7))
        {
            _delegate = new Queen(getOwner());
            _delegate->setLocation(getLocation());
        }
    }
    return canMove;
}


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
    string displayString;
    if (hasBeenPromoted())
    {
        displayString = _delegate->display();
    }
    else
    {
        string value = getOwner().display();
        displayString = (value + "P");
    }
    return displayString;
}


bool Pawn::isOnOtherEnd()
{
    //
}


bool Pawn::canMoveTo(Square* location)
{
    bool retVal = false;
    if (hasBeenPromoted())
    {
        retVal = _delegate->canMoveTo(location);
    }
    else
    {
        if (location != getLocation())
        {
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
                            if (getOwner().getBoard()->canClearColumn(location, getLocation()))
                            {
                                retVal = true;
                            }
                        }
                    }
                }
                if (getLocation()->getColumn() - location->getColumn() == 1 ||
                    getLocation()->getColumn() - location->getColumn() == -1)
                {
                    if (getLocation()->getRow() - location->getRow() == 1)
                    {
                        if (location->occupiedBy() == 1)
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
                        if (location->occupiedBy() == 0)
                        {
                            retVal = true;
                        }
                    }
                }
            }
        }
    }
    return retVal;
}

bool Pawn::hasBeenPromoted()
{
    return _delegate != nullptr;
}

bool Pawn::hasJustDoubleMoved()
{
    return _justDoubleMoved;
}
