#ifndef COURSE_H
#define COURSE_H
#include "Time.h"
#include <string>
using namespace std;
/*
Purpose: Class that holds information on the course

Functions:
computeDays(): Sets given days to days set by the course
computeSlot(): Sets given Time slot depending on course time
lessThan(): Should given course be infront or after current course
*many getters and setter

Vars:
time: Time of given course

*/


class Course
{

public:
    Course(string="", string="", int=0, char=' ', string="", LectDaysType=BAD_LECT_DAYS, int=0,int=0);
    ~Course();
    void print();
    bool computeDays(WeekDayType&, WeekDayType&);
    bool computeSlot(TimeSlotType&);
    bool lessThan(Course*);
    int getID();
    string getTerm();
    string getInstructor();
    void setID(int);
    void getCode();

private:
    int id;
    string term;
    string subject;
    int code;
    char section;
    string instructor;
    LectDaysType days;
    Time *time;
};

#endif
