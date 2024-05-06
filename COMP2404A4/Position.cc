#include "Position.h"
#include "defs.h"

Position::Position(int r, int c)
{
    if (r < 0)
    {
        row = 0;
    }
    else if (r > MAX_ROW - 1)
    {
        row = MAX_ROW - 1;
    }
    else
    {
        row = r;
    }
    
    if (c < 0)
    {
        col = 0;
    }
    else if (c > MAX_COL)
    {
        col = MAX_COL;
    }
    else
    {
        col = c;
    }
    
}

Position::~Position() {}

void Position::set(int r, int c)
{
    if (r <= 0)
    {
        row = 1;
    }
    else if (r > MAX_ROW - 1)
    {
        row = MAX_ROW - 1;
    }
    else
    {
        row = r;
    }
    
    if (c < 0)
    {
        col = 0;
    }
    else if (c > MAX_COL)
    {
        col = MAX_COL;
    }
    else
    {
        col = c;
    }
}

bool Position::equals(Position* p)
{
    return (row == p->row && col == p->col);
}

int Position::getRow()
{
    return row;
}

int Position::getCol()
{
    return col;
}


