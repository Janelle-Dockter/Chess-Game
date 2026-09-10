// jdockter17@georgefox.edu
// Assignment 10
// 2019-04-29


#ifndef _PIECE_H
#define _PIECE_H

#include <string>

using namespace std;

class Square;
class Player;
class Board;

/**
 * Abstract class of all types of chess Pieces. Allows for all to be referenced as "Piece".
 */
class Piece
{
    public:

        /**
         * Constructs an instance of a chess Piece given a player that is the owner of the piece.
         */
        Piece(Player& owner);

        /**
         * Gets the move description of the Piece.
         */
        virtual void getMoveDescription() = 0;

        // Note: will eventually be return type vector<Square*>
        /**
         * Gets the Square options for the Piece to move to from its current location.
         * @return A collection of pointers to Square objects that this Piece could move to.
         */
        virtual Square* getMoveOptions() = 0;

        /**
         * Gets the Square options for the Pawn to move to from a given location.
         * @param location The location to calculate possible move options.
         * @return A collection of pointers to Square objects that this piece could move to.
         */
        virtual Square* getMoveOptions(Square& location) = 0;

        /**
         * Gets the name of the piece.
         * @return The name of the piece.
         */
        virtual string getName() = 0;

        /**
         * Constructs a string representation of the Piece, with the owner's color prepended.
         * @return The string representation of the Piece.
         */
        virtual string display() = 0;

        /**
         * Determines if the piece can move to a given location.
         * @param location The location to check if the piece can move to.
         * @return True if the piece can move there, False otherwise.
         */
        virtual bool canMoveTo(Square* location) = 0;

        /**
         * Moves the current Piece to a new location.
         * @param location The location to move the Piece to.
         * @return True if the piece successfully moved to the location, False otherwise.
         */
        virtual bool move(Square* location);

        /**
         * Determines if the current piece has moved yet.
         * @return True if the current piece has moved, False otherwise.
         */
        bool hasMoved();

        /**
         * Checks the hasMoved switch to make sure the piece knows it has moved before.
         */
        void makeHasMoved();

        /**
         * This piece becomes captured by the other opponent.
         */
        void getCapturedByOpponent();

        /**
         * Gets the color of the Piece.
         * @return 0 if color is white, 1 if color is black.
         */
        int getColor();

        /**
         * Gets the current location of the Piece.
         * @return A pointer to the square the Piece is currently located on.
         */
        Square* getLocation();

        /**
         * Sets the location of the piece to a given Square.
         * @param location A reference to the new Square location of the piece.
         */
        void setLocation(Square* location);

        /**
         * Determines if the Piece is still on the Board.
         * @return True if the Piece is captured, False otherwise.
         */
        bool isCaptured();

        /**
         * Gets the owner of the Piece.
         * @return A reference to the Player that owns the Piece.
         */
        Player& getOwner();

    private:
        bool _hasMoved = false;
        Square* _location;
        Player& _owner;
};

#endif //_PIECE_H