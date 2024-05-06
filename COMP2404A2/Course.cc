using namespace std;
#include <iomanip>
#include <iostream>

#include "Course.h"

Course::Course(string t, string sub, int c, char sec, string i, LectDaysType d, int h, int m)
{
    id = 0;
    term = t;
    subject = sub;
    code = c;
    instructor = i;
    section = sec;
    days = d;
    time = new Time(h,m);

}

Course::~Course()
{

    delete time;

}

bool Course::computeDays(WeekDayType& day1, WeekDayType& day2)
{

    if (days == MON_WED)
    {
        day1 = MON;
        day2 = WED;
        return true;
    }
    else if (days == TUE_THU)
    {
        day1 = TUE;
        day2 = THU;    
        return true;
    }  
    else if (days == WED_FRI)
    {
        day1 = WED;
        day2 = FRI;
        return true;

    }
    else
    {
        return false;
    }

}

bool Course::computeSlot(TimeSlotType& slot)
{

    return time->computeSlot(slot);

}

bool Course::lessThan(Course* course)
{
    if (subject < course->subject) 
    {
        return true;
    } 
    else if (subject > course->subject) 
    {
        return false;
    }

    if (code > course->code)
    {
        return true;
    } 
    else if (code < course->code) 
    {
        return false;
    }

    if (term < course->term) 
    {
        return true;
    } 
    else if (term > course->term) 
    {
        return false;
    }

    return section > course->section;
     
}

int Course::getID()
{
    return id;
}

string Course::getTerm()
{
    return term;
}

string Course::getInstructor()
{
    return instructor;
}

void Course::setID(int i)
{
    id = i;
}

void Course::print()
{
    cout << setfill(' ');

    cout<< id << "  Term: " << setw(6) << left << term << subject 
        << " " << code << " " << setw(4) << section;

    if (days == 0)
    {
        cout << "MW ";
    }
    else if (days == 1)
    {
        cout << "TR ";
    }
    else 
    {
        cout << "WF ";
    }
    time->print();
    cout<< setw(2) << " Instr: " << instructor << endl;

}

void Course::getCode()
{

    cout << subject << " " << code << "-" << section;

}
