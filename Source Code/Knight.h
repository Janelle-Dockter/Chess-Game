#ifndef _KNIGHT_H
#define _KNIGHT_H

#include "Piece.h"
#include "Square.h"
#include "Player.h"


class Knight: public Piece
{
    using Piece::Piece;

    public:

        /**
         * Prints the move description of a Knight: A move with the slope of 2/1 or 1/2 in any direction.
         */
        void getMoveDescription();

        // NOTE: This method will eventually return a vector<Square*>, but currently I don't want to mess with my implementation.

        /**
         * Gets the Square options for the Knight to move to from its current location.
         * @return A collection of pointers to Square objects that this Knight could move to.
         */
        Square* getMoveOptions();

        /**
         * Gets the Square options for the Knight to move to from a given location.
         * @param location The location to calculate possible move options.
         * @return A collection of pointers to Square objects that this Knight could move to.
         */
        Square* getMoveOptions(Square& location);

        /**
         * Gets the name of the piece.
         * @return "Knight".
         */
        string getName();

        /**
         * Determines if the piece can move to a given location.
         * @param location The location to check if the piece can move to.
         * @return True if the piece can move there, False otherwise.
         */
        bool canMoveTo(Square* location);

        /**
         * Gets the string representation of a Knight: "N" with "B" or "W" prepended.
         * @return The string representation of the Knight.
         */
        string display();
};

#endif //_KNIGHT_H