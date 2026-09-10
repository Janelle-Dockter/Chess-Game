// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


#ifndef _CHESSGAME_H
#define _CHESSGAME_H

#include "Board.h"
#include "Player.h"

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
        int getNextPlayer();

        /**
         * Switch to the next player's turn.
         */
        void switchPlayers();

        /**
         * Begins the next turn of the chess game.
         */
        void nextTurn();

    private:
        Board _gameBoard;
        Player _first;
        Player _second;
        Player* _currentPlayer;
};

#endif //_CHESSGAME_H