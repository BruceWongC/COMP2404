#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Student.h"
#include "Course.h"

/*
Purpose: Regs for a student and their course
Func: 
- lessThan: if Reg is less than given reg
- getStu: Get std pointer

Var:
- nextID: used to get next id for reg
- id: id of reg
- student: std ptr
- course: course ptr

*/

class Registration
{
    public:
        Registration(Student*, Course*);
        ~Registration();
        bool lessThan(Registration*);
        void print();
        Student* getStu();

    private:
        static int nextID;
        int id;
        Student* student;
        Course* course;

};

#endif
