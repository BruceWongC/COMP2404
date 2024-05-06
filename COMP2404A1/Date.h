#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;


/*
Purpose: The Date of a given event

Fucntions:
Date: Constructor
set(int, int, int): Set variables with given values
set(Date& d): Set variables with values from given Date class
equals: Is Date object equal to given Date object
lessthan: Does Date object happen before given Date object or not
validate: Is given values of date valid
*/

class Date
{
  public:
    Date(int=0, int=0, int=2000);
    void set(int, int, int);
    void set(Date&);
    bool equals(Date& d);
    bool lessThan(Date& d);
    bool validate(int, int, int);
    void print();

  private:
    int    day;
    int    month;
    int    year;

    int  lastDayInMonth(int, int);
    bool leapYear(int);
    string getMonthStr(int);
};

#endif
