#ifndef STUARRAY_H
#define STUARRAY_H
#include "Student.h"
#include "defs.h"

/*
Purpose: Array for students
Func:
- add: add std to array
- find: find std in array with num

Vars:
- elements: array of std
- size: size of array

*/

class StuArray
{
    public:
        StuArray();
        ~StuArray();
        void add(Student*);
        bool find(string num, Student**);
        void print();

    private:
        Student* elements[MAX_ARR];
        int size;
};


#endif