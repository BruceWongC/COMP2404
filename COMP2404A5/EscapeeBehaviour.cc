#include "EscapeeBehaviour.h"
#include "defs.h"
#include "Escape.h"

EscapeeBehaviour::EscapeeBehaviour() {}

EscapeeBehaviour::~EscapeeBehaviour() {}

void EscapeeBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{
    int moveCol = random(3);
    int moveRow = random(5);    

    switch (moveCol)
    {
    case 1:
        moveCol = 1; 
        break;
    case 2:
        moveCol = -1;
        break;
    default:
        moveCol = 0;
        break;
    }

    switch (moveRow)
    {
    case 1:
        moveRow = 1; 
        break;
    case 2:
        moveRow = 2;
        break;
    case 3:
        moveRow = -1;
        break;
    case 4:
        moveRow = -2;
        break;
    default:
        moveRow = 0;
        break;
    }


    if (Escape::withinBounds(oldRow + moveRow, oldCol + moveCol))
    {
        newRow = oldRow + moveRow;
        newCol = oldCol + moveCol;

    }

}