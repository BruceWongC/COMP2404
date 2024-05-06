#ifndef SNORC_H
#define SNORC_H

#include <string>
using namespace std;
#include "Participant.h"

/*
Purpose: A derived participant that do damage to heros in the sim
Func: 
- move: Movement oppertunity
- incurDamage: Take damage 
- causeDamage: Cause damage

Var:
- strength: how much damage they would deal
*/

class Snorc : public Participant
{
    public:
        Snorc(int=0,int=0,int=0);
        ~Snorc();
        void move(Pit*);
        void incurDamage(Participant*);
        int causeDamage();


    private:
        int strength;

};

#endif
