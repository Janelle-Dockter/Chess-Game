// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include "Board.h"
#include "Player.h"
#include "GameMove.h"

/**
 * Class that connects the Players of the game to the chess Board itself. Manages the chess game.
 */
class ChessGame
{
    public:

        /**
         * Constructs a new ChessGame, which prompts for Players to choose their color and name, along with creating a
         * new board.
         */
        ChessGame();

        /**
         * Returns the results of the current game being played.
         */
        void getResults();

        /**
         * Starts the ChessGame, which will continue until won or force quit by a Player
         */
        void initiate();

        /**
         * Gets the Player who's turn is next (opposite of who is currently on their turn).
         * @return
         */
        Player* getNextPlayer();

        /**
         * Initiates the next turn of the game.
         */
        void nextTurn();

    private:
        Board _gameBoard;
        Player _first;
        Player _second;
        Player* _currentPlayer;
        GameMove _history;
};

#endif //_CHESSGAME_H