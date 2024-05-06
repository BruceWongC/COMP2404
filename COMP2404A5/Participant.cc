#include "Participant.h"

Participant::Participant(char a, int r, int c, MoveBehaviour* m)
{

    avatar = a;
    dead = false;
    row = r;
    col = c;
    movement = m;


}

Participant::~Participant()
{
    delete movement;
}

void Participant::move()
{

    movement->move(row, col, row, col);

}

char Participant::getAvatar()
{
    return avatar;
}

int Participant::getRow()
{
    return row;
}

int Participant::getCol()
{
    return col;
}

bool Participant::isDead()
{
    return dead;
}