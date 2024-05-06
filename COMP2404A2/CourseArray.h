#ifndef COURSEARRAY_H
#define COURSEARRAY_H

#include "defs.h"
#include "Course.h"

/*
Purpose: Be the array of Courses to be accessed

Functions:
add(): Add course to array
find(): Find if course is in array

vars:
elements: array of courses
size: size of array

*/

class CourseArray
{
  public:
    CourseArray();
    ~CourseArray();
    void add(Course*);
    void print(string);
    bool find(int, Course**);

  private:
    Course* elements[MAX_ARR];
    int   size;
};


#endif
