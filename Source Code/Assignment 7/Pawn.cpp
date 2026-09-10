// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#include "Pawn.h"

using namespace std;

/**
 * Pawn implementation
 */

// Additional implementation will be added.

void Pawn::getMoveDescription()
{
    //
}

Square* Pawn::getMoveOptions()
{
    //
}

Square* Pawn::getMoveOptions(Square& location)
{

}

string Pawn::display()
{
    string value = getOwner().display();
    return (value + "P");
}
