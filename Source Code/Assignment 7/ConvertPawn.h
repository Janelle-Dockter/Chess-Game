// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _CONVERTPAWN_H
#define _CONVERTPAWN_H

#include "ChessMove.h"

class Piece;

/**
 * Subclass of Move that allows for the piece in question (a Pawn) to be converted to another type of Piece.
 */
class ConvertPawn: public ChessMove
{
    public:

        /**
         * Converts the current Pawn to a new type of Piece.
         * @param newPiece The new type of Piece to convert the Pawn to.
         */
        void convertedTo(Piece* newPiece);
};

#endif //_CONVERTPAWN_H