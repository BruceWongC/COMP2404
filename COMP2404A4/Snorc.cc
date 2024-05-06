#include "Snorc.h"

Snorc::Snorc(int r, int c, int s) : Participant('s',r,c), strength(s) {}

Snorc::~Snorc(){}

void Snorc::move(Pit* p)
{
    //0/2 = up/left, 1 = down/right

    int rowDir = random(2);
    int colDir = random(3);
    
    if (rowDir == 0)
    {
        rowDir = -1;
    }

    if (colDir == 2)
    {
        colDir = -1;
    }
    //0 = no movement
    
    if (p->withinBounds(pos->getRow(), pos->getCol() + colDir)) //changes col 
    {
        pos->set(pos->getRow(), pos->getCol() + colDir);
    }

    if (rowDir == 1 || pos->getRow() - 1 > MAX_ROW - 9) //changes row if meets requirements
    {
        if (p->withinBounds(pos->getRow() + rowDir, pos->getCol()))
        {
            pos->set(pos->getRow() + rowDir, pos->getCol());
        }   
    }

}

void Snorc::incurDamage(Participant* p) {}

int Snorc::causeDamage()
{
    return strength;
}