#ifndef SNORC_H
#define SNORC_H

#include <string>
using namespace std;
#include "Participant.h"

/*
Purpose: A derived participant that do damage to heros in the sim
Func: 
- isSafe: Are they safe (always false)
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
        void incurDamage(Participant*);
        int causeDamage();
        bool isSafe();


    private:
        int strength;

};

#endif
