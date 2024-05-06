#ifndef POSITION_H
#define POSITION_H

/*
Purpose: The row or col for participant 
Func:
- equals: if row and col are equal
- set: sets row and col to given params
- get...: getter functions

Var:
- row and col: row and col for position

*/

class Position
{
    public:
        Position(int=0, int=0);
        ~Position();
        bool equals(Position*);
        void set(int, int);
        int getRow();
        int getCol();

    private:
        int row;
        int col;    
};

#endif