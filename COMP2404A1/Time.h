#ifndef TIME_H
#define TIME_H

/*
Purpose: Time for a given event 

Functions:
Time: Constructor
set: Sets time hour and mins variable for the class
lessThan: Check if Time class happens before the given Time class or not
validate: Is given values a valid time
convertToMins: Convert time to mins

*/

class Time
{
  public:
    Time(int=0, int=0);
    void set(int, int);
    void set(Time&);
    void print();
    bool lessThan(Time&);
    bool validate(int, int);

  private:
    int hours;
    int minutes;
    int convertToMins();
};

#endif
