// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#include "Piece.h"
#include "Player.h"
#include "Square.h"

using namespace std;

/**
 * Piece implementation
 */

// Additional implementation will be added later.

Piece::Piece(Player& owner): _owner(owner) {}


void Piece::move(Square& location)
{
    _location = &location;
}

void Piece::getCapturedByOpponent()
{
    _location == nullptr;
    _owner.losePiece(this);
}


bool Piece::canMoveTo(Square& location)
{
    return false;
}


int Piece::getColor()
{
    return _owner.getColor();
}


Square* Piece::getLocation()
{
    return _location;
}


void Piece::setLocation(Square& location)
{
    _location = &location;
}


bool Piece::isCaptured()
{
    return (_location != nullptr);
}


Player& Piece::getOwner()
{
    return _owner;
}