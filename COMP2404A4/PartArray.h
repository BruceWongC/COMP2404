#ifndef ARRAY_H
#define ARRAY_H

#include "Participant.h"
#include "defs.h"

/*
Purpose: Array to hold participants

Func:
- add: add to array
- get: get participant from given index 

*/

class PartArray
{
  public:
    PartArray();
    ~PartArray();
    void add(Participant*);
    Participant* get(int);
    int getSize();

  private:
    Participant* elements[MAX_ARR];
    int   size;
};

#endif

