// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"
#include "Square.h"
#include "Player.h"


/**
 * Class Bishop that is a subclass of a chess Piece. Moves diagonally.
 */
class Bishop: public Piece
{
    /**
     * Uses default constructor of Piece class.
     */
    using Piece::Piece;

    public:

        /**
         * Prints a description of Bishop's general move: Diagonal, cannot jump other pieces.
         */
        void getMoveDescription();

        // NOTE: This method will eventually return a vector<Square*>, but currently I don't want to mess with my implementation.
        /**
         * Gets the Square options for the Bishop to move to from its current location.
         * @return A collection of pointers to Square objects that this Bishop could move to.
         */
        Square* getMoveOptions();

        /**
         * Gets the Square options for the Bishop to move to from a given location.
         * @param location The location to calculate possible move options.
         * @return A collection of pointers to Square objects that this Bishop could move to.
         */
        Square* getMoveOptions(Square& location);

        /**
         * Finds a string version of the Bishop, which is simply B with B or W prepended.
         * @return The string representation of the Bishop.
         */
        string display();
};

#endif //_BISHOP_H