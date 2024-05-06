#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "MoveBehaviour.h"

/*
Purpose: Abstract class for every participant in the sim
Func:
- incurDamage, causeDamage, isSafe: Pure virtual functions for derived classes
- isDead: If participant is dead
- move: move participant in a certain way

var:
- dead: are they active in sim
- movement: Type of movement they will move

*/

class Participant
{
    public:
        Participant(char=' ', int=0, int=0, MoveBehaviour* = nullptr); //move behaviour needs to be added
        virtual ~Participant();
        virtual void incurDamage(Participant*) = 0;
        virtual int causeDamage() = 0;
        virtual bool isSafe() = 0;
        void move();
        char getAvatar();
        int getRow();
        int getCol();
        bool isDead();

    protected:
        char avatar;
        bool dead;
        int row;
        int col;
        MoveBehaviour* movement;
        
};

#endif
