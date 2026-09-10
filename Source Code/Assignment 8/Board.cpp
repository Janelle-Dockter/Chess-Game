// jdockter17@georgefox.edu
// Assignment 8
// 2019-04-06


#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

using namespace std;

/**
 * Board implementation
 */

// More implementation to be added later.

Board::Board() {}

//* FIX THIS DESTRUCTOR LATER.
Board::~Board()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
        {
            if (getSquareAt(i, j).isOccupied())
            {
                delete getSquareAt(i, j).getOccupant();
            }
        }
    }
}

void Board::setUp(Player* p1, Player* p2)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Square square = Square(i, j);
            _board[i][j] = square;
            Player* player = p2;
            if (i == 7 || i == 6)
            {
                player = p1;
            }
            // For the first and last rows, add all advanced pieces in order.
            if (i == 0 || i == 7)
            {
                if (j == 0 || j == 7)
                {
                    Piece* piece = new Rook(*player);
                    _board[i][j].setOccupant(piece);
                    player -> addPiece(piece);
                }
                if (j == 1 || j == 6)
                {
                    Piece* piece = new Knight(*player);
                    _board[i][j].setOccupant(piece);
                    player -> addPiece(piece);
                }
                if (j == 2 || j == 5)
                {
                    Piece* piece = new Bishop(*player);
                    _board[i][j].setOccupant(piece);
                    player -> addPiece(piece);
                }
                if (j == 3)
                {
                    Piece* piece = new Queen(*player);
                    _board[i][j].setOccupant(piece);
                    player -> addPiece(piece);
                }
                if (j == 4)
                {
                    Piece* piece = new King(*player);
                    _board[i][j].setOccupant(piece);
                    player -> addPiece(piece);
                }
            }

            // For the second and second to last rows, make all pieces Pawns.
            if (i == 1 || i == 6)
            {
                Piece* piece = new Pawn(*player);
                _board[i][j].setOccupant(piece);
                player -> addPiece(piece);
            }
        }
    }
    display();
}

void Board::display()
{
    cout << "     a    b    c    d    e    f    g    h    " << endl;
    cout << "  +----+----+----+----+----+----+----+----+  " << endl;

    // Prints the location of each piece on the board (or lack of piece) with numbers on the side for visual.
    for (int i = 0; i < 8; i++)
    {
        cout << 8 - i << " | ";
        for (int j = 0; j < 8; j++)
        {
            cout << _board[i][j].display() << " | ";
        }
        cout << 8 - i << endl;
        cout << "  +----+----+----+----+----+----+----+----+  " << endl;
    }
    cout << "     a    b    c    d    e    f    g    h    " << endl;
}

void Board::reset()
{
    // To Do
}


Square& Board::getSquareAt(int row, int column)
{
    return _board[row][column];
}


bool Board::canClearRow(Square& from, Square& to)
{
    return false;
}


bool Board::canClearColumn(Square& to, Square& from)
{
    return false;
}


bool Board::canClearDiagonal(Square& to, Square& from)
{
    return false;
}