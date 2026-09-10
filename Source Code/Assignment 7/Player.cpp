// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#include "Player.h"
#include "Piece.h"
#include "Board.h"
#include "ChessMove.h"
#include "Castle.h"
#include "ConvertPawn.h"
#include "Capture.h"

using namespace std;

/**
 * Player implementation
 */

// Additional implementation will be added later.

Player::Player(string name, int color): _color(color), _name(name)
{
    // Not sure if I will need this or not, leaving it in for now.
    //_capturedPieces = vector<Piece*>();
    //_pieces = vector<Piece*>();
}


void Player::setName()
{
    string name;
    cout << colorString() << " pick player name: ";
    getline(cin, name);
}

void Player::setBoard(Board& board)
{
    _board = &board;
}


ChessMove* Player::getMoveChoice()
{
    bool valid = false;
    string moveChoice;
    while (!valid)
    {
        cout << colorString() << " enter move: ";
        getline(cin, moveChoice);
        // check if each move is valid
        // add method that converts input to row and column int

        if (moveChoice.length() == 5)
        {
            if (isValidColumn(moveChoice.at(0)) && isValidColumn(moveChoice.at(3)))
            {
                if (moveChoice.at(2) == ' ')
                {
                    if (isValidRow(moveChoice.at(1)) && isValidRow(moveChoice.at(4)))
                    {
                        valid = true;
                    }
                }
            }
        }
    }
    Square& start = getSquare(moveChoice.at(1), moveChoice.at(0));
    Square& end = getSquare(moveChoice.at(4), moveChoice.at(3));
    Piece* occupant = start.getOccupant();
    // Add a filter for special moves, like castling, converting a pawn, and capturing
    GameMove* chessMove = new ChessMove(occupant, start, end);
    return nullptr;
}


Square& Player::getSquare(char& row, char& column)
{
    int intRow = convertRow(row);
    int intColumn = convertColumn(column);
    return _board->getSquareAt(intRow, intColumn);
}


int Player::convertRow(char& row)
{
    int retVal = 8 - stoi(&row);
    return retVal;
}

int Player::convertColumn(char& column)
{
    bool retVal;
    if (column == 'a')
    {
        retVal = 0;
    }
    else if (column == 'b')
    {
        retVal = 1;
    }
    else if (column == 'c')
    {
        retVal = 2;
    }
    else if (column == 'd')
    {
        retVal = 3;
    }
    else if (column == 'e')
    {
        retVal = 4;
    }
    else if (column == 'f')
    {
        retVal = 5;
    }
    else if (column == 'g')
    {
        retVal = 6;
    }
    else if (column == 'h')
    {
        retVal = 7;
    }
    return retVal;
}


bool Player::isValidRow(char& row)
{
     bool valid = false;
     if (row == '8' || row == '7')
     {
         valid = true;
     }
     else if (row == '6' || row == '5')
     {
         valid = true;
     }
     else if (row == '4' || row == '3')
     {
         valid = true;
     }
     else if (row == '2' || row == '1')
     {
         valid = true;
     }
     return valid;
}


bool Player::isValidColumn(char& column)
{
    bool valid = false;
    if (column == 'a' || column == 'b')
    {
        valid = true;
    }
    else if (column == 'c' || column == 'd')
    {
        valid = true;
    }
    else if (column == 'e' || column == 'f')
    {
        valid = true;
    }
    else if (column == 'g' || column == 'h')
    {
        valid = true;
    }
    return valid;
}


bool Player::hasLostGame()
{
    return false;
}


void Player::addPiece(Piece* piece)
{
    _pieces.push_back(piece);
}


void Player::losePiece(Piece* piece)
{
    // To Do
}


Piece* Player::getKing()
{
    return nullptr;
}

int Player::getColor()
{
    return _color;
}


string Player::colorString()
{
    string color = "Black";
    if (_color == 0)
    {
        color = "White";
    }
    return color;
}


string Player::display()
{
    string value = "B";
    if (_color == 0)
    {
        value = "W";
    }
    return value;
}