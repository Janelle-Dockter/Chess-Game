// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


#include "Square.h"
#include "Piece.h"
#include <iostream>

using namespace std;

/**
 * Square implementation
 */

// More implementation will be added later.

Square::Square() {}


Square::Square(int row, int column): _row(row), _column(column) {}


bool Square::isOccupied()
{
    return (_piece != nullptr);
}


int Square::occupiedBy()
{
    int occupant = -1;
    if (isOccupied())
    {
        occupant = getOccupant()->getColor();
    }
    return occupant;
}


bool Square::kingCanMoveHere(int color)
{
    return (color != _offLimits);
}


void Square::makeOffLimits(int kingColor)
{
    // Verify 0 or 1
    _offLimits = kingColor;
}


Piece* Square::getOccupant()
{
    return _piece;
}


void Square::setOccupant(Piece* occupant)
{
    _piece = occupant;
    if (occupant != nullptr)
    {
        _piece->setLocation(this);
    }
}


int Square::getRow()
{
    return _row;
}


int Square::getColumn()
{
    return _column;
}

string Square::display()
{
    string value = "  ";
    if (isOccupied())
    {
        value = getOccupant() -> display();
    }
    return value;
}