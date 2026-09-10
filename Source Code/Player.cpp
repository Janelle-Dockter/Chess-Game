#include "Player.h"
#include "Piece.h"
#include "Board.h"

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

Board* Player::getBoard()
{
    return _board;
}

void Player::setOpponent(Player& opponent)
{
    _opponent = &opponent;
}

Player* Player::getOpponent()
{
    return _opponent;
}

void Player::getMoveChoice()
{
    bool valid = false;
    string moveChoice;
    Square* end;
    Piece* occupant;
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
        else if (moveChoice.length() == 6)
        {
            if (moveChoice.at(5) == '=')
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

        if (valid)
        {
            Square& start = getSquare(moveChoice.at(1), moveChoice.at(0));
            end = &getSquare(moveChoice.at(4), moveChoice.at(3));
            // Checks if the player is forfeiting by tipping their own king over.
            if (&start == getKing()->getLocation() && end == getKing()->getLocation())
            {
                valid = true;
                getKing()->getCapturedByOpponent();

            }
            else if (!start.isOccupied())
            {
                valid = false;
                cout << "Error: No piece to move." << endl;
            }
            else
            {
                occupant = start.getOccupant();
                // Checks if the occupant is the same color as the player moving right now.
                if (occupant->getColor() != getColor())
                {
                    valid = false;
                    cout << "Error: Not your piece to move." << endl;
                }
                // Checks if the occupant can geometrically move to the location.
                if (!occupant->canMoveTo(end))
                {
                    valid = false;
                    cout << "Error: Piece cannot move there." << endl;
                }
                // The move to piece is a bit broken so I isolated it.
                if (valid)
                {
                    // Checks if the move submitted will put the own player's king in check, also moves the piece if there
                    // is no issue.
                    if (!occupant->move(end))
                    {
                        valid = false;
                        cout << "Error: Do not put your own king in check!" << endl;
                    }
                        // Takes player out of check if a successful move is made.
                    else
                    {
                        _isInCheck = false;
                        _drawOffered = false;
                    }
                }
            }
        }

        // Checks if the move just made puts the other opponent in check.
        if (valid)
        {
            if (willPutInCheck(getOpponent()->getKing()->getLocation()))
            {
                cout << getOpponent()->getName() << " in check!" << endl;
                getOpponent()->putInCheck();
            }
        }

        // Handles the two valid single character moves (both forfeiting).
        if (moveChoice.length() == 1 && (_isInCheck || _drawOffered))
        {
            if (moveChoice.at(0) == '#' && _isInCheck)
            {
                valid = true;
                getKing()->getCapturedByOpponent();
            }
            if (moveChoice.at(0) == '=' && _drawOffered)
            {
                valid = true;
                getKing()->getCapturedByOpponent();
            }
        }
        // Handles draw offering.
        if (moveChoice.length() == 6)
        {
            if (moveChoice.at(5) == '=')
            {
                getOpponent()->offerDraw();
            }
        }

    }
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
    int retVal;
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
    return getKing() == nullptr;
}


void Player::addPiece(Piece* piece)
{
    _pieces.push_back(piece);
}


void Player::losePiece(Piece* piece)
{
    list<Piece*> tempPieces;
    for (auto* comparing : _pieces)
    {
        if (comparing != piece)
        {
            tempPieces.push_back(comparing);
        }
    }
    vector<Piece*> pieces;
    copy(tempPieces.begin(),tempPieces.end(),back_inserter(pieces));
    _pieces = pieces;
}


void Player::offerDraw()
{
    _drawOffered = true;
}


Piece* Player::getKing()
{
    Piece* king = nullptr;
    for (auto* piece : _pieces)
    {
        if (piece->getName() == "King")
        {
            king = piece;
        }
    }
    return king;
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


string Player::getName()
{
    string value = "Black";
    if (_color == 0)
    {
        value = "White";
    }
    return value;
}


void Player::putInCheck()
{
    _isInCheck = true;
}


bool Player::willPutInCheck(Square* kingLocation)
{
    bool willPutInCheck = false;
    for (auto* piece : _pieces)
    {
        if (piece->canMoveTo(kingLocation))
        {
            willPutInCheck = true;
        }
    }
    return willPutInCheck;
}