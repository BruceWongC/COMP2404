#ifndef HERO_H
#define HERO_H

#include "defs.h"
#include <string>
using namespace std;
#include "Participant.h"

/*
Purpose: A derived participant who are 1 of 2 people in the sim
Func: 
- incurDamage: Take damage and check type of dmg
- causeDamage: Cause damage (0)
- isSafe: Checks if Hero should be taken out of sim

Vars:
- rescue: If it collides with ninja 

*/

class Hero : public Participant
{
    public:
        Hero(char=' ',int=0,int=0,string="");
        ~Hero();
        void incurDamage(Participant*);
        int causeDamage();
        bool isSafe();
        string getName();
        int getHealth();
        bool getRescue();

    private:
        string name;
        int health;
        bool rescue;

};

#endif
