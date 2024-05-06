#include "RescuedBehaviour.h"
#include "defs.h"
#include "Escape.h"

RescuedBehaviour::RescuedBehaviour() {}

RescuedBehaviour::~RescuedBehaviour() {}

void RescuedBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{
    
    if (Escape::withinBounds(oldRow - 1, oldCol))
    {
        newRow = oldRow - 1;
    }
}