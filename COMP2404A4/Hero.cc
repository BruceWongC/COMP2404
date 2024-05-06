#include "Hero.h"

Hero::Hero(char a, int r, int c, string s) : Participant(a,r,c), name(s), health(MAX_HEALTH) {}

Hero::~Hero() {}

void Hero::move(Pit* p)
{
    if (isDead() || isSafe())
    {
        return;
    }

    int moveRow = 0;
    moveRow = random(10);
 
    if (moveRow % 2 == 0) // 1 row up
    {
        moveRow = -1;            
    }
    else if (moveRow == 5) // 2 rows up
    {
        moveRow = -2;           
    }
    else // down a row
    {
        moveRow = 1;            
    } 

    int moveCol = 0;
    moveCol = random(5);

    if (moveCol == 1)
    {
        moveCol = -1; //1 left 
    }
    else if (moveCol == 2)
    {
        moveCol = -2; //2 left
    }
    else if (moveCol == 3)
    {
        moveCol = 1; //1 right
    }
    else if (moveCol == 4)
    {
        moveCol = 2; //2 right
    }
    
    //0 = no movement



    if (p->underLedge(pos))
    {
        moveCol = random(2);

        if (moveCol == 0)
        {
            moveCol = -1;
        }
                
        if (p->validPos(pos->getRow(), pos->getCol() + moveCol))
        {
            pos->set(pos->getRow(), pos->getCol() + moveCol);
        }
        
    }
    else
    {
        if (p->validPos(pos->getRow() + moveRow, pos->getCol() + moveCol))
        {
            pos->set(pos->getRow() + moveRow, pos->getCol() + moveCol);
        }   
    }

}

void Hero::incurDamage(Participant* p)
{
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

string Hero::getName()
{
    return name;
}

int Hero::getHealth()
{
    return health;
}