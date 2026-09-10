// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _PLAYER_H
#define _PLAYER_H

#include "King.h"
#include "GameMove.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Piece;

class Board;

class ChessMove;
class Castle;
class ConvertPawn;
class Capture;

/**
 * A Player in the game of Chess, will either be white or black.
 */
class Player
{
    public:

        /**
         * Constructs a new instance of a Player, given a name and color.
         * @param name The name of the Player, given by the user.
         * @param color The color of the Player: 0 for White, 1 for Black.
         */
        Player(string name, int color);

        /**
         * Prompts the user to pick a name for their player.
         */
        void setName();

        /**
         * Tells the player what Board they are currently playing on.
         * @param board The board the players are using.
         */
        void setBoard(Board& board);

        /**
         * Finds the square given a row and column.
         * @param row The row to get the square at.
         * @param column The column to get the square at.
         * @return The square pointer to get at the given row and column.
         */
        Square& getSquare(char& row, char& column);

        /**
         * Converts the row from a character given by the user to an integer.
         * @param row The character row given by the user.
         * @return The integer version of the row.
         */
        static int convertRow(char& row);

        /**
         * Converts the column from a character given by the user to an integer.
         * @param column The character column given by the user.
         * @return The integer version of the column.
         */
        static int convertColumn(char& column);

        /**
         * Checks if the given row is valid.
         * @param row The character representing row from the user.
         * @return True if the input is valid, False otherwise.
         */
        static bool isValidRow(char& row);

        /**
         * Checks if a given column is valid.
         * @param column The character representing column from the user.
         * @return True if the input is valid, False otherwise.
         */
        static bool isValidColumn(char& column);

        /**
         * Gets the desired move choice from the user.
         * @return The move that the user decided on.
         */
        ChessMove* getMoveChoice();

        /**
         * Determines if the current Player still has a King in their set of Pieces.
         * @return True if the Player lost the game, False otherwise.
         */
        bool hasLostGame();

        /**
         * Adds a new Piece to Player's collection of Pieces (not captured Pieces).
         * @param piece The Piece to add to the Player's collection.
         */
        void addPiece(Piece* piece);

        /**
         * Removes a Piece from a Player's collection of Pieces (not captured Pieces).
         * @param piece The Piece to remove from the Player's collection.
         */
        void losePiece(Piece* piece);

        /**
         * Gets the King of the Player.
         * @return The King of the Player.
         */
        Piece* getKing();

        /**
         * Gets the color of the Player.
         * @return 0 if the Player is white, 1 if the Player is black.
         */
        int getColor();

        /**
         * Gets the string version of the player's color.
         * @return "Black" or "White".
         */
        string colorString();

        /**
         * Gets the string representation of the Player's color: "B" for black (1), "W" for white (0).
         * @return The string representation of the Player's color.
         */
        string display();

    private:
        Board* _board;
        int _color;
        string _name;
        vector<Piece*> _pieces;
        //vector<Piece*> _capturedPieces;
};

#endif //_PLAYER_H