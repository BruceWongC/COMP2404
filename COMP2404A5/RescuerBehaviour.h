#ifndef RESCUERBEHAVIOUR_H
#define RESCUERBEHAVIOUR_H

#include "MoveBehaviour.h"

/*
Purpose: MoveBehaviour of a Rescuer

Functions:
- move: Move participant 1 row down 
*/


class RescuerBehaviour : public MoveBehaviour
{
    public:
        RescuerBehaviour();
        ~RescuerBehaviour();
        void move(int,int,int&,int&);
};


#endif

