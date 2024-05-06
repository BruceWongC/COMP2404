#ifndef ESCAPEEBEHAVIOUR_H
#define ESCAPEEBEHAVIOUR_H

#include "MoveBehaviour.h"

/*
Purpose: MoveBehaviour of a Escapee

Functions:
- move: Move participant around in the pit, as long as it's a valid spot

*/

class EscapeeBehaviour : public MoveBehaviour
{
    public:
        EscapeeBehaviour();
        ~EscapeeBehaviour();
        void move(int,int,int&,int&);
};


#endif

