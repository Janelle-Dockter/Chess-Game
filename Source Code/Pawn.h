// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


#ifndef _PAWN_H
#define _PAWN_H

#include "Piece.h"
#include "Player.h"
#include "Square.h"
#include "Queen.h"

/**
 * Subclass of Piece that populates the front row of each Player's lineup.
 */
class Pawn: public Piece
{
    using Piece::Piece;

    public:

        /**
         * Moves the current Piece to a new location.
         * @param location The location to move the Piece to.
         * @return True if the piece successfully moved to the location, False otherwise.
         */
        bool move(Square* location);


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
         * Determines if this pawn is on the row at the other side of the board.
         * @return True if the pawn is on the opposite end.
         */
        bool isOnOtherEnd();

        /**
         * Determines if the piece can move to a given location.
         * @param location The location to check if the piece can move to.
         * @return True if the piece can move there, False otherwise.
         */
        bool canMoveTo(Square* location);

        /**
         * Determines if the pawn has been promoted to a queen.
         * @return True if the pawn has been promoted, False otherwise.
         */
        bool hasBeenPromoted();

        /**
         * Determines if the pawn has just double moved in the game.
         * @return True if the pawn has just double moved, False otherwise.
         */
        bool hasJustDoubleMoved();

    private:
        Piece* _delegate = nullptr;
        bool _justDoubleMoved = false;
};

#endif //_PAWN_H