#ifndef HERO_H
#define HERO_H

#include <string>
using namespace std;
#include "Participant.h"

/*
Purpose: A derived participant who are 1 of 2 people in the sim
Func: 
- move: Movement oppertunity
- incurDamage: Take damage
- causeDamage: Cause damage
*/

class Hero : public Participant
{
    public:
        Hero(char=' ',int=0,int=0,string="");
        ~Hero();
        void move(Pit*);
        void incurDamage(Participant*);
        int causeDamage();
        string getName();
        int getHealth();

    private:
        string name;
        int health;

};

#endif
