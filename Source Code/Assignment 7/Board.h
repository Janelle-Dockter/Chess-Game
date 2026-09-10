// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _BOARD_H
#define _BOARD_H

#include "Square.h"
#include "Player.h"

#include <iostream>

/**
 * Represents a Chess board containing squares for the game to be played on.
 */
class Board
{
    public:

        /**
         * Constructs a Board object, and does nothing else.
         */
        Board();

        /**
         * Sets the board up with initial placement of all pieces, can serve as a start or reset for the game.
         * @param p1 A pointer to the white player.
         * @param p2 A pointer to the black player.
         */
        void setUp(Player* p1, Player* p2);

        /**
         * Destructs the Board object, including deleting each piece that was "new"-ed in setUp method.
         */
        ~Board();



        /**
         * Displays the game board with current placements of all pieces.
         */
        void display();

        /**
         * Resets the board to starting position of all pieces.
         */
        void reset();

        /**
         * Returns a reference to the Square object at a given location on the board.
         * @param row The row containing the desired Square.
         * @param column The column containing the desired Square.
         * @return The reference to the Square object at the given location.
          */
        Square& getSquareAt(int row, int column);

        /**
         * Determines if all Squares in the row between two Squares are empty.
         * @param from The starting Square in the row of Squares.
         * @param to The ending Square in the row of Squares.
         * @return True if all Squares between are unoccupied, False otherwise.
         */
        bool canClearRow(Square& from, Square& to);

        /**
         * Determines if all Squares in the column between two Squares are empty.
         * @param to The starting Square in the column of Squares.
         * @param from The ending Square in the column of Squares.
         * @return True if all Squares between are unoccupied, False otherwise.
         */
        bool canClearColumn(Square& to, Square& from);

        /**
         * Determines if all Squares diagonal between two Squares are empty.
         * @param from The starting Square in the diagonal group of Squares.
         * @param to The ending Square in the diagonal group of Squares.
         * @return True if all Squares between are unoccupied, False otherwise.
         */
        bool canClearDiagonal(Square& to, Square& from);

    private:
        Square _board[8][8];
};

#endif //_BOARD_H