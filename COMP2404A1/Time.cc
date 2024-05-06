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

void Time::set(Time& t)
{

  set(t.hours, t.minutes);

}

bool Time::lessThan(Time& t)
{

  return t.convertToMins() > convertToMins();
  
}

bool Time::validate(int h, int m)
{

  return(h >= 0 && h < 24 && m >= 0 && m < 60);

}


int Time::convertToMins()
{
  return (hours*60 + minutes);

}

void Time::print()
{
  cout<<setfill('0')<<setw(2)<<right<<hours<<":"
      <<setfill('0')<<setw(2)<<minutes;

}

