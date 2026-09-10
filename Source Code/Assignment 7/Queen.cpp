// jdockter17@georgefox.edu
// Assignment 7
// 2019-03-23


#include "Queen.h"

using namespace std;

/**
 * Queen implementation
 */

// Additional implementation will be added later.

void Queen::getMoveDescription()
{
    //
}

Square* Queen::getMoveOptions()
{
    //
}

Square* Queen::getMoveOptions(Square& location)
{
    //
}


string Queen::display()
{
    string value = getOwner().display();
    return (value + "Q");
}

