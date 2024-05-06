#ifndef NINJA_H
#define NINJA_H

#include "Participant.h"

/*
Purpose: Sub class of participant

Functions:
- incurDamage: Checks the type of dmg dealt to choose it's next move
- causeDamage: Do -1 damage (rescue) or deal dmg if poisoned
- isSafe: Are they safe/bring them about of the sim

Vars:
- strength: dmg to deal if poisoned or to rescue
- poisoned: If ninja should be big Snorc

*/

class Ninja : public Participant
{
    public:
        Ninja(int=0,int=0);
        ~Ninja();
        void incurDamage(Participant*);
        int causeDamage();
        bool isSafe();

    private:
        int strength;
        bool poisoned;

};



#endif
