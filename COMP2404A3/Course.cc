#include "Course.h"
#include <iostream>
#include <iomanip>
#include "defs.h"

int Course::nextID = COURSE_ID;

Course::Course(string t, string sub, int c, char s, string i)
{

    id = nextID;
    term = t;
    subject = sub;
    code = c;
    section = s;
    instructor = i;
    nextID++;
}

Course::~Course(){}

bool Course::lessThan(Course* c)
{

    if (term > c->term) 
    {
        return true;
    } 
    else if (term < c->term) 
    {
        return false;
    }

    if (subject > c->subject) 
    {
        return true;
    } 
    else if (subject < c->subject) 
    {
        return false;
    }

    if (code > c->code)
    {
        return true;
    } 
    else if (code < c->code) 
    {
        return false;
    }


    return section > c->section;
    

}

void Course::print()
{
    cout << setw(6) << left << id << "Term: " << setw(6) << term;
    getCID();
    cout << " Instr: " << instructor << endl;
}

int Course::getID()
{
    return id;
}

string Course::getTerm()
{
    return term;
}

void Course::getCID()
{
    cout << subject << " " << code << "-" << section;
}