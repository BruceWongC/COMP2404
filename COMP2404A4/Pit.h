#ifndef PIT_H
#define PIT_H
#include "defs.h"
#include "Position.h"


/*
Purpose: Simulates the Snorc pit

Func: 
- validPos: Validates if given row or col are within boundaries
- withinBounds: Validates if given row or col are within boundaries and not on a ledge
- underLedge: If the next index is a ledge or "-"

var:
- layout: The layout of the snorc pit

*/

class PartArray;
class Hero;

class Pit
{
    public:
        Pit(const char[MAX_ROW + 1][MAX_COL + 1]);
        ~Pit();
        bool validPos(int, int);
        bool withinBounds(int,int);
        bool underLedge(Position*);
        void print(PartArray*, Hero*, Hero*);                

    private:
        char layout[MAX_ROW + 1][MAX_COL + 1];

};

#endif
