#ifndef SCHEDULE_h
#define SCHEDULE_H
#include <string>
#include "Course.h"


/*
Purpose: Hold courses that would be in the given day and time

Function: 
addCourse(): add course to schedule
clear(): clear elements arr to all indexs to NULL
getTerm(): getter for term

vars:
term: name of term
elements: 2d array of courses for the 5 days and 7 time slots

*/

class Schedule
{

    public:
        Schedule(string="");
        ~Schedule();
        bool addCourse(Course*);
        void print();
        void clear();
        string getTerm();

    private:
        string term;
        Course* elements[NUM_DAYS][NUM_SLOTS];

};


#endif