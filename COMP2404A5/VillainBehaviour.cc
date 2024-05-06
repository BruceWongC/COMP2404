#include "VillainBehaviour.h"
#include "defs.h"
#include "Escape.h"

VillainBehaviour::VillainBehaviour() {}

VillainBehaviour::~VillainBehaviour() {}

void VillainBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{

    int moveCol = random(3);
    int moveRow = random(2);

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

    if (moveRow == 0)
    {
        moveRow = -1;
    }



    if (oldRow + moveRow < MAX_ROW + 1 && oldRow + moveRow > MAX_ROW - 7)
    {
        if (Escape::withinBounds(oldRow + moveRow, oldCol + moveCol))
        {
            newRow = oldRow + moveRow;
            newCol = oldCol + moveCol;
        }
    }
    else
    {
        if (Escape::withinBounds(oldRow, oldCol + moveCol))
        {
            newCol = oldCol + moveCol;
        }
    }
    
    

}