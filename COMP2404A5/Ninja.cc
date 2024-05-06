#include "Ninja.h"
#include "VillainBehaviour.h"
#include "RescuerBehaviour.h"
#include "RescuedBehaviour.h"
#include "defs.h"

Ninja::Ninja(int r, int c) : Participant('N', r, c, new RescuerBehaviour()),strength(0), poisoned(false){}

Ninja::~Ninja(){}

void Ninja::incurDamage(Participant* p)
{
    if (poisoned == true)
    {
        return;
    }
    else if (p->causeDamage() == RESCUE)
    {
        return;
    }
    else if (p->causeDamage() == 0)
    {
        delete movement;
        movement = new RescuedBehaviour();
    }
    else
    {
        poisoned = true;
        int num = random(3) + 6;
        strength = num;
        avatar = 'S';
        delete movement;
        movement = new VillainBehaviour();

    }

}

int Ninja::causeDamage() 
{
    if (poisoned == true)
    {
        return strength;
    }

    return RESCUE;
    
}

bool Ninja::isSafe()
{    
    if ((row <= 1 || row >= MAX_ROW) && !poisoned)
    {
        return true;
    }
    
    return false;

}