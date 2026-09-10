// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#ifndef _PIECE_H
#define _PIECE_H

#include <string>

using namespace std;

class Square;
class Player;

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
         * @return A collection of pointers to Square objects that this Pawn could move to.
         */
        virtual Square* getMoveOptions(Square& location) = 0;


        /**
         * Constructs a string representation of the Piece, with the owner's color prepended.
         * @return The string representation of the Piece.
         */
        virtual string display() = 0;

        /**
         * Moves the current Piece to a new location.
         * @param location The location to move the Piece to.
         */
        void move(Square& location);

        /**
         * This piece becomes captured by the other opponent.
         */
        void getCapturedByOpponent();

        // Make canMoveTo virtual
        /**
         * Determines if the piece can move to a given location.
         * @param location The place for the Piece to move to.
         */
        bool canMoveTo(Square& location);

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
        void setLocation(Square& location);

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
        bool _stuckOnSquare = false;
};

#endif //_PIECE_H