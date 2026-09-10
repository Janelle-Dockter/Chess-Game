#ifndef _PLAYER_H
#define _PLAYER_H

#include "King.h"
#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Piece;

class Board;

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
     * Gets the board that the player is playing on.
     * @return A pointer to the chess board object that is being played on.
     */
    Board* getBoard();

    /**
     * Sets the opponent of the current player to another player.
     * @param opponent The opponent of the current player.
     */
    void setOpponent(Player& opponent);

    Player* getOpponent();

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
     */
    void getMoveChoice();

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
     * Flags the player that the opponent offered a draw;
     */
    void offerDraw();

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

    /**
     * Gets the string representation of the Player's name: "Black" or "White".
     * @return The string representation of the Player's name.
     */
    string getName();

    /**
     * Puts the current player in check.
     */
    void putInCheck();

    /**
     * Determines if this player will put the other player's king in check.
     * @param kingLocation The location of the other player's king (don't need this parameter, will delete later).
     * @param freedSpace The space that is now freed from the other players (maybe) move.
     * @param takenSpace The space that the other player's piece is (maybe) moving to.
     * @return True if this player will put the other player in check, false otherwise.
     */
    bool willPutInCheck(Square* kingLocation);

private:
    Board* _board;
    int _color;
    string _name;
    vector<Piece*> _pieces;
    Player* _opponent;
    bool _drawOffered = false;
    bool _isInCheck = false;
    //vector<Piece*> _capturedPieces;
};

#endif //_PLAYER_H