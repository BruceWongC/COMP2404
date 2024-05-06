#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include "Pit.h"
#include "Position.h"

/*
Purpose: Base class for every participant in the sim
Func:
- move, incurDamage, causeDamage: Pure virtual functions for derived classes
- collide: Are positions equal
- isDead: If participant is dead
- isSafe: Are they on row 1/exited the program

var:
- dead: are they active in sim
- pos: Position of participant

*/

class Participant
{
    public:
        Participant(char=' ', int=0, int=0);
        virtual ~Participant();
        virtual void move(Pit*) = 0;
        virtual void incurDamage(Participant*) = 0;
        virtual int causeDamage() = 0;
        bool collide(Participant*);
        char getAvatar();
        int getRow();
        int getCol();
        bool isDead();
        bool isSafe();

    protected:
        char avatar;
        bool dead;
        Position* pos;
        
};

#endif
