// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#ifndef _QUEEN_H
#define _QUEEN_H

#include "Piece.h"
#include "Player.h"
#include "Square.h"


/**
 * The Queen Piece in the game of Chess, one of the move valuable and can move many Squares in any direction.
 */
class Queen: public Piece
{
    using Piece::Piece;

    public:

        /**
         * Prints the move description of a Queen: Any number of Squares horizontally, vertically, or diagonally, but
         * a Queen cannot jump other pieces.
         */
        void getMoveDescription();

        // NOTE: This method will eventually return a vector<Square*>, but currently I don't want to mess with my implementation.

        /**
         * Gets the Square options for the Queen to move to from its current location.
         * @return A collection of pointers to Square objects that this Queen could move to.
         */
        Square* getMoveOptions();

        /**
         * Gets the Square options for the Queen to move to from a given location.
         * @param location The location to calculate possible move options.
         * @return A collection of pointers to Square objects that this Queen could move to.
         */
        Square* getMoveOptions(Square& location);

        /**
         * Gets the name of the piece.
         * @return "Queen".
         */
        string getName();

        /**
         * Determines if the piece can move to a given location.
         * @param location The location to check if the piece can move to.
         * @return True if the piece can move there, False otherwise.
         */
        bool canMoveTo(Square* location);

        /**
         * Gets the string version of a Queen: "Q" with "B" or "W" prepended.
         * @return The string version of Queen.
         */
        string display();
};

#endif //_QUEEN_H