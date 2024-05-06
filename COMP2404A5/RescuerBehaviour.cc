#include "RescuerBehaviour.h"
#include "defs.h"
#include "Escape.h"

RescuerBehaviour::RescuerBehaviour() {}

RescuerBehaviour::~RescuerBehaviour() {}

void RescuerBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{
    if (Escape::withinBounds(oldRow + 1, oldCol))
    {
        newRow = oldRow + 1;
    }   
}