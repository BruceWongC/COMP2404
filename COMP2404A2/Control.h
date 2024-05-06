#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "Schedule.h"

/*
Purpose: Controls the program/is the reason it launches

Fucntions:
launch(): starts the program that main runs
initCourses(): adds courses to the school
addSched(): Adds schedule to array
findSched(): Find given schedule 

vars:
numScheds: # of schedules
ptr: school pointer
arr: array of schedules
*/

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    int numScheds;
    School* ptr;
    Schedule* arr[MAX_ARR];

    void initCourses(School*);
    bool addSched(Schedule*);
    bool findSched(string, Schedule**);

};

#endif
