#ifndef MOVEBEHAVIOUR_H
#define MOVEBEHAVIOUR_H

/*
Purpose: Abstract class for all 4 possible movement types

Functions:
- move: Pure virtual function that is used for sub classes

*/

class MoveBehaviour
{
    public:
        MoveBehaviour();
        ~MoveBehaviour();
        virtual void move(int,int,int&,int&) = 0;
};


#endif

