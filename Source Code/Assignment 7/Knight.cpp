// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#include "Knight.h"

using namespace std;

/**
 * Knight implementation
 */

// Other implementation will be added later.

void Knight::getMoveDescription()
{
    //
}

Square* Knight::getMoveOptions()
{
    //
}

Square* Knight::getMoveOptions(Square& location)
{

}

string Knight::display()
{
    string value = getOwner().display();
    return (value + "N");
}

