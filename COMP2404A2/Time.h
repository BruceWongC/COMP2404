#ifndef TIME_H
#define TIME_H
#include "defs.h"

/*
Purpose: Time for a course

Functions:
computeSlot(): set given parameter to correct enum depending on hours and min
setFromSlot(): set time of Time class depending on TimeSlotType


*/

class Time
{
  public:
    Time(int=0, int=0);
    void print();
    bool computeSlot(TimeSlotType&);
    bool setFromSlot(TimeSlotType);
  private:
    int  hours;
    int  minutes;
    void set(int, int);
    int  convertToMins();
};

#endif
