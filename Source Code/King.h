#ifndef _KING_H
#define _KING_H

#include "Piece.h"
#include "Square.h"
#include "Player.h"

/**
 * Subclass of Piece, King has additional behavior because capturing a King is the way to end a chess game.
 */
class King: public Piece
{
    // Class King uses Piece's constructor.
    using Piece::Piece;

    public:

        /**
         * Determines if the King is in check at its current location.
         * @return True if the King is currently in check, False otherwise.
         */
        bool isInCheck();

        // Add a method to determine if the King is in check GIVEN a location.

        /**
         * Prints the move description of the King: one Square in any direction.
         */
        void getMoveDescription();

        // NOTE: This method will eventually return a vector<Square*>, but currently I don't want to mess with my implementation.
        /**
         * Gets the Square options for the King to move to from its current location.
         * @return A collection of pointers to Square objects that this King could move to.
         */
        Square* getMoveOptions();

        /**
         * Gets the name of the piece.
         * @return "King".
         */
        string getName();

        /**
         * Determines if the piece can move to a given location.
         * @param location The location to check if the piece can move to.
         * @return True if the piece can move there, False otherwise.
         */
        bool canMoveTo(Square* location);

        /**
         * Gets the Square options for the King to move to from a given location.
         * @param location The location to calculate possible move options.
         * @return A collection of pointers to Square objects that this King could move to.
         */
        Square* getMoveOptions(Square& location);

        /**
         * Gets a string representation of the King, which is "K" with "B" or "W" prepended.
         * @return The string representation of the King.
         */
        string display();
};

#endif //_KING_H