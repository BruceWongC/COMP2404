#ifndef RESCUEDBEHAVIOUR_H
#define RESCUEDBEHAVIOUR_H

#include "MoveBehaviour.h"

/*
Purpose: MoveBehaviour of a Rescued participant

Functions:
- move: Move participant 1 row up

*/

class RescuedBehaviour : public MoveBehaviour
{
    public:
        RescuedBehaviour();
        ~RescuedBehaviour();
        void move(int,int,int&,int&);
};


#endif

