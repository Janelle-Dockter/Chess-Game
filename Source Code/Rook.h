// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


#ifndef _ROOK_H
#define _ROOK_H

#include "Piece.h"
#include "Player.h"
#include "Square.h"
#include "Board.h"


/**
 * Rook is a subtype of Piece that can move horizontally or vertically any number of Squares.
 */
class Rook: public Piece
{
    using Piece::Piece;

    public:

        /**
         * Prints the move description of Rook: Any number of Squares horizontally or vertically.
         */
        void getMoveDescription();

        // NOTE: This method will eventually return a vector<Square*>, but currently I don't want to mess with my implementation.

        /**
         *Gets the Square options for the Rook to move to from its current location.
         * @return A collection of pointers to Square objects that this Rook could move to.
         */
        Square* getMoveOptions();

        /**
         * Gets the Square options for the Rook to move to from a given location.
         * @param location The location to calculate possible move options.
         * @return A collection of pointers to Square objects that this Rook could move to.
         */
        Square* getMoveOptions(Square& location);

        /**
         * Gets the name of the piece.
         * @return "Rook".
         */
        string getName();

        /**
         * Determines if the piece can move to a given location.
         * @param location The location to check if the piece can move to.
         * @return True if the piece can move there, False otherwise.
         */
        bool canMoveTo(Square* location);

        /**
         * Gets the string representation of the Rook: "R" with "B" or "W" prepended.
         * @return The string representation of the Rook.
         */
        string display();
};

#endif //_ROOK_H