#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  set(h, m);
}

void Time::set(int h, int m)
{
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

int Time::convertToMins()
{
  return (hours*60 + minutes);

}

void Time::print()
{
  cout << right << setfill('0')<<setw(2)<<hours<<":"
       << right << setfill('0')<<setw(2)<<minutes;
}

bool Time::computeSlot(TimeSlotType& slot)
{
  if (hours == 8 && minutes == 30)
  {
    slot = SLOT_0830;
    return true;
  }
  else if (hours == 10 && minutes == 00)
  {
    slot = SLOT_1000;
    return true;
  }
  else if (hours == 11 && minutes == 30)
  {
    slot = SLOT_1130;
    return true;
  }
  else if (hours == 13 && minutes == 00)
  {
    slot = SLOT_1300;
    return true;
  }  
  else if (hours == 14 && minutes == 30)
  {
    slot = SLOT_1430;
    return true;
  }
  else if (hours == 16 && minutes == 00)
  {
    slot = SLOT_1600;
    return true;
  }
  else if (hours == 18 && minutes == 00)
  {
    slot = SLOT_1800;
    return true;
  }
  return false;

}

bool Time::setFromSlot(TimeSlotType slot)
{
  switch (slot)
  {
  case SLOT_0830:
    hours = 8;
    minutes = 30;
    break;
  case SLOT_1000:
    hours = 10;
    minutes = 0;
    break;
  case SLOT_1130:
    hours = 11;
    minutes = 30;
    break;
  case SLOT_1300:
    hours = 13;
    minutes = 0;
    break;
  case SLOT_1430:
    hours = 14;
    minutes = 30;
    break;
  case SLOT_1600:
    hours = 16;
    minutes = 0;
    break;
  case SLOT_1800:
    hours = 18;
    minutes = 0;
    break;
  
  default:
    return false;
  }

  return true;


}

