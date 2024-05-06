#ifndef VILLAINBEHAVIOUR_H
#define VILLAINBEHAVIOUR_H

#include "MoveBehaviour.h"

/*
Purpose: MoveBehaviour of a Villain

Functions:
- move: Move participant if it's a valid space
*/


class VillainBehaviour : public MoveBehaviour
{
    public:
        VillainBehaviour();
        ~VillainBehaviour();
        void move(int,int,int&,int&);
};


#endif

