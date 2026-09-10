// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#ifndef _PAWN_H
#define _PAWN_H

#include "Piece.h"
#include "Player.h"
#include "Square.h"


/**
 * Subclass of Piece that populates the front row of each Player's lineup.
 */
class Pawn: public Piece
{
    using Piece::Piece;

    public:

        /**
         * Prints a description of the Pawn's move: one Square forward, two if first time moving Piece, or one Square
         * diagonally if capturing.
         */
        void getMoveDescription();

        // NOTE: will eventually be of type vector<Square*>.
        /**
         * Gets the Square options for the Pawn to move to from its current location.
         * @return A collection of pointers to Square objects that this Pawn could move to.
         */
        Square* getMoveOptions();

        /**
         * Gets the Square options for the Pawn to move to from a given location.
         * @param location The location to calculate possible move options.
         * @return A collection of pointers to Square objects that this Pawn could move to.
         */
        Square* getMoveOptions(Square& location);

        /**
         * Gets the name of the piece.
         * @return "Pawn".
         */
        string getName();

        /**
         * Forms the string representation of Pawn: "P" with "B" or "W" prepended.
         * @return The string representation of this Pawn.
         */
        string display();

        /**
         * Determines if the piece can move to a given location.
         * @param location The location to check if the piece can move to.
         * @return True if the piece can move there, False otherwise.
         */
        bool canMoveTo(Square* location);

};

#endif //_PAWN_H