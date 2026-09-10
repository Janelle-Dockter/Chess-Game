// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


#ifndef _SQUARE_H
#define _SQUARE_H

#include <string>
using namespace std;

class Piece;

/**
 * Class Square populates a Chess Board and can contain an occupant that is a Piece.
 */
class Square
{
    public:

        /**
         * Constructs an arbitrary Square object with no location on the Board.
         */
        Square();

        /**
         * Constructs a Square at a given location on the Board.
         * @param row The row of the Square.
         * @param column The column of the Square.
         */
        Square(int row, int column);

        /**
         * Determines if the Square currently holds a Chess Piece.
         * @return True if the Square is occupied, False otherwise.
         */
        bool isOccupied();

        /**
         * Determines if the square is occupied by an opponent, and if so, which color.
         * @return -1 if no occupant, 0 if occupied by white piece, 1 if occupied by a black piece.
         */
        int occupiedBy();

        /**
         * Determines if a King can move to this Square.
         * @param color The color of the King wanting to move to the Square
         * @return True if the King of the given color can move to the Square, False otherwise.
         */
        bool kingCanMoveHere(int color);

        /**
         * Makes a square off limits to the King of a given color.
         * @param kingColor The color of the King to make the Square off limits to.
         */
        void makeOffLimits(int kingColor);

        /**
         * Gets the current occupant of the Square.
         * @return The Piece occupant of the Square if occupied.
         */
        Piece* getOccupant();

        /**
         * Sets the occupant of the Square to a given Piece.
         * @param occupant A pointer to the Piece that is the new occupant of the square.
         */
        void setOccupant(Piece* occupant);

        /**
         * Gets the row of the Square on the Board.
         * @return The row of the Square on the Board.
         */
        int getRow();

        /**
         * Gets the column of the Square on the Board.
         * @return The column of the Square on the Board.
         */
        int getColumn();

        /**
         * Gets a string representation of the Square: Double space if empty, the Pieces string version if occupied.
         * @return The string representation of the Square.
         */
        string display();

    private:
        int _row;
        int _column;
        Piece* _piece = nullptr;
        int _offLimits = -1;
};

#endif //_SQUARE_H