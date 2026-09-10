// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _CAPTURE_H
#define _CAPTURE_H

#include "ChessMove.h"

class Piece;

/**
 * Subtype of Move, which is a type of ChessMove. Allows a piece to take out another piece in addition to just changing
 * Squares.
 */
class Capture: public ChessMove
{
    private:
        Piece& _pieceToCapture;
};

#endif //_CAPTURE_H