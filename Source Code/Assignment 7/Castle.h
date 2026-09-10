// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _CASTLE_H
#define _CASTLE_H

#include "GameMove.h"
#include "Rook.h"
#include "King.h"
// CHANGED INHERETANCE FROM CHESS MOVE TO MOVE
/**
 * Subtype of Move, which is a type of ChessMove. Allows the King's side Rook and the King to perform the castling
 * move that moves both Pieces at the same time.
 */
class Castle: public GameMove
{
    private:
        Rook& _rook;
        King& _king;
};

#endif //_CASTLE_H