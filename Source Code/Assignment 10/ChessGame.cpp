// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


#include "ChessGame.h"

using namespace std;

/**
 * ChessGame implementation
 */


ChessGame::ChessGame(): _first(Player("", 0)), _second(Player("", 1)), _gameBoard(Board())
{
    _currentPlayer = &_first;
    _first.setBoard(_gameBoard);
    _second.setBoard(_gameBoard);
    _first.setOpponent(_second);
    _second.setOpponent(_first);
    //_first.setName();
    //_second.setName();
}


void ChessGame::initiate()
{
    _gameBoard.setUp(&_first, &_second);
    bool gameOver = false;
    while (!gameOver)
    {
        nextTurn();
        if (_currentPlayer->hasLostGame())
        {
            gameOver = true;
        }
        switchPlayers();
        if (!gameOver)
        {
            _gameBoard.display();
        }
    }
}


void ChessGame::getResults()
{
    // To Do
}


int ChessGame::getNextPlayer()
{
    int next = 1;
    if (_currentPlayer == &_second)
    {
        next = 0;
    }
    return next;
}


void ChessGame::switchPlayers()
{
    int next = getNextPlayer();
    if (next == 0)
    {
        _currentPlayer = &_first;
    }
    else
    {
        _currentPlayer = &_second;
    }
}


void ChessGame::nextTurn()
{
    _currentPlayer->getMoveChoice();
}