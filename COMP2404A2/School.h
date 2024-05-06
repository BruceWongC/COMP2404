#ifndef SCHOOL_h
#define SCHOOL_H

#include "CourseArray.h"

/*
Purpose: Main body for the school and hold courseArray and name of school

Functions: 
addCourse(): add course to course array
findCourse(): find if course is in array

vars:
arr: array of Courses

*/

class School
{

    public:
        School(string="");
        ~School();
        void addCourse(Course*);
        bool findCourse(int, Course**);
        void printCourses(string);

    private:
        string name;
        CourseArray arr;
        

};


#endif