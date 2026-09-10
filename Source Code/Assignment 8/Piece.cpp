// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#include "Piece.h"
#include "Player.h"
#include "Square.h"

using namespace std;

/**
 * Piece implementation
 */

// Additional implementation will be added later.

Piece::Piece(Player& owner): _owner(owner) {}


void Piece::move(Square* location)
{
    if (location->isOccupied())
    {
        location->getOccupant()->getCapturedByOpponent();
    }
    _location->setOccupant(nullptr);
    _location = location;
    _location->setOccupant(this);
    _hasMoved = true;
}

bool Piece::hasMoved()
{
    return _hasMoved;
}

void Piece::getCapturedByOpponent()
{
    _location = nullptr;
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