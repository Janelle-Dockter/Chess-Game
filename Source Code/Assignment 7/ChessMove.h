// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _MOVE_H
#define _MOVE_H

#include "GameMove.h"

class Piece;
class Square;

/**
 * Typical chess Move that is a realization of the ChessMove interface.
 */
class ChessMove: public GameMove
{
    public:

        /**
         * Moves a chess Piece from one Square to another.
         * @param piece The piece to move on the Board.
         * @param to The Square the piece started at.
         * @param from The Square the piece is going to.
         */
        ChessMove(Piece* piece, Square* to, Square* from);

        /**
         * Gets the piece that the Move is working on.
         * @return The piece that is contained in the current move.
         */
        Piece* getPiece();

    private:
        Piece* _piece;
        Square* _to;
        Square* _from;
};

#endif //_MOVE_H