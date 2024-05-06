#ifndef COURSEARRAY_H
#define COURSEARRAY_H
#include "Course.h"
#include "defs.h"

/*
Purpose: Array for courses
Func: 
- add: add course to array
- find: find course with given id and give it to double pointer 
- print(string): print courses with given term

Var:
- elements: Array of courses
- size: size of array

*/

class CourseArray
{
    public:
        CourseArray();
        ~CourseArray();
        void add(Course*);
        bool find(int, Course**);
        void print();
        void print(string);

    private:
        Course* elements[MAX_ARR];
        int size;
};


#endif
