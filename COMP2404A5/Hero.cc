#include "Hero.h"
#include "EscapeeBehaviour.h"
#include "RescuedBehaviour.h"

Hero::Hero(char a, int r, int c, string s) : Participant(a,r,c, new EscapeeBehaviour()), name(s), health(MAX_HEALTH), rescue(false){}

Hero::~Hero() {}

void Hero::incurDamage(Participant* p)
{
    if (p->causeDamage() == RESCUE)
    {
        rescue = true;
        delete movement;
        movement = new RescuedBehaviour();
        return;
    }

    health -= p->causeDamage();

    if (health <= 0)
    {
        health = 0;
        dead = true;
        avatar = '+';
    }


}

int Hero::causeDamage()
{
    return 0;
}

bool Hero::isSafe()
{
    if (row <= 1)
    {
        return true;
    }
    
    return false;
}

string Hero::getName()
{
    return name;
}

int Hero::getHealth()
{
    return health;
}

bool Hero::getRescue()
{
    return rescue;
}