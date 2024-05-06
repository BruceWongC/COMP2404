#include "Participant.h"

Participant::Participant(char c, int row, int col)
{

    avatar = c;
    dead = false;
    pos = new Position(row, col);

}

Participant::~Participant()
{
    delete pos;
}

bool Participant::collide(Participant* p)
{
    return (pos->equals(p->pos));
}

char Participant::getAvatar()
{
    return avatar;
}

int Participant::getRow()
{
    return pos->getRow();
}

int Participant::getCol()
{
    return pos->getCol();
}

bool Participant::isDead()
{
    return dead;
}

bool Participant::isSafe()
{
    if (pos->getRow() <= 1)
    {
        return true;
    }
    
    return false;
}