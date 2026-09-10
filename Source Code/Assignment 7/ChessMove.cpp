// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#include "ChessMove.h"
#include "Piece.h"
#include "Square.h"

/**
 * Move implementation.
 */

ChessMove::ChessMove(Piece* piece, Square* to, Square* from): _piece(piece), _to(to), _from(from) {}

Piece* ChessMove::getPiece()
{
    return _piece;
}