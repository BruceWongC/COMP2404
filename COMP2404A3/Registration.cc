#include "Registration.h"
#include "defs.h"
#include <iostream>
#include <iomanip>

int Registration::nextID = REG_ID;

Registration::Registration(Student* s, Course* c)
{
    id = nextID;
    student = s;
    course = c;
    nextID++;
}

Registration::~Registration(){}

Student* Registration::getStu()
{
    return student;
}

bool Registration::lessThan(Registration* r)
{
    return course->lessThan(r->course);
}

void Registration::print()
{

    cout << setw(7) << left << id << setw(14) << student->getName() << setw(6) << course->getTerm();
    course->getCID();
    cout << endl;

}

