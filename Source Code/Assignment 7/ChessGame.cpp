// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


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
    //_first.setName();
    //_second.setName();
}


void ChessGame::initiate()
{
    _gameBoard.setUp(&_first, &_second);
}


void ChessGame::getResults()
{
    // To Do
}


Player* ChessGame::getNextPlayer()
{
    Player next = _second;
    if (_currentPlayer == &_second)
    {
        next = _first;
    }
    return &next;
}


void ChessGame::nextTurn()
{
    ChessMove* move = _currentPlayer->getMoveChoice();
    _currentPlayer = getNextPlayer();
}