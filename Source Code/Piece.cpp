#include "Piece.h"
#include "Player.h"
#include "Square.h"
#include "Board.h"

using namespace std;

/**
 * Piece implementation
 */

// Additional implementation will be added later.

Piece::Piece(Player& owner): _owner(owner) {}


bool Piece::move(Square* location)
{
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
        //getOwner().getBoard()->remove(startingOtherPiece);
    }
    return canMove;
}

bool Piece::hasMoved()
{
    return _hasMoved;
}

void Piece::makeHasMoved()
{
    _hasMoved = true;
}

void Piece::getCapturedByOpponent()
{
    getLocation()->setOccupant(nullptr);
    setLocation(nullptr);
    _owner.losePiece(this);
}


int Piece::getColor()
{
    return _owner.getColor();
}


Square* Piece::getLocation()
{
    return _location;
}


void Piece::setLocation(Square* location)
{
    _location = location;
}


bool Piece::isCaptured()
{
    return (_location != nullptr);
}


Player& Piece::getOwner()
{
    return _owner;
}