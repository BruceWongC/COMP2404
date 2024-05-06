#include "Schedule.h"
#include <iostream>
#include <iomanip>

using namespace std;

Schedule::Schedule(string s)
{

    term = s;
    for (int i = 0; i < BAD_WEEK_DAY; i++)
    {
        for (int j = 0; j < BAD_TIME_SLOT; j++)
        {
            elements[i][j] = NULL;
        }

    }

}

Schedule::~Schedule(){}


bool Schedule::addCourse(Course*c)
{

    if (c == NULL)
    {
        cout << "ERROR: Course is NULL";
        return false;

    }
    else if (c->getTerm() != term)
    {
        cout << "ERROR: Course does not match";
        return false;
    }

    WeekDayType day1 = BAD_WEEK_DAY, day2 = BAD_WEEK_DAY;
    c->computeDays(day1, day2);
    
    TimeSlotType t = BAD_TIME_SLOT;
    c->computeSlot(t);

    elements[day1][t] = c;
    elements[day2][t] = c;

    return true;

}

void Schedule::print()
{
    Time t;
    cout << endl << endl << "   SCHEDULE FOR CURRENT TERM:  " << term << endl;
    cout << setfill('-');
    cout << setw(105) << "" << endl; 
    cout << setfill(' ');
    cout << "|" << setw(19) << right << "MON" << setw(18) << right << "TUE"
         << setw(18) << right << "WED" << setw(18) << right << "THU" 
         << setw(18) << right << "FRI" << setw(13) << "|" << endl;

    for (int i = 0; i < NUM_SLOTS; i++)
    {
        cout << setfill('-');

        cout << setw(105) << "" << endl; 
        cout << setfill(' ');

        t.setFromSlot(TimeSlotType(i));
        cout << "| ";
        t.print();
        cout << " |" << setfill(' ');

        //print all codes
        for (int j = 0; j < NUM_DAYS; j++)
        {
            if (elements[j][i] != NULL)
            {
                elements[j][i]->getCode();
                cout << setw(8) << "";
            }
            else
            {
                cout << setw(19) << "";
            }

        }
        cout << "|"<< endl;
        

        cout << "|       |";
        //print all ids
        for (int j = 0; j < NUM_DAYS; j++)
        {
            if (elements[j][i] != NULL)
            {
                cout << "CN:  " << elements[j][i]->getID() << setw(10) << "";
            }
            else
            {
                cout << setw(19) << "";
            }        
        }
        cout << "|"<< endl;



        cout << "|       |";
        //print all intructs
        for (int j = 0; j < NUM_DAYS; j++)
        {
            if (elements[j][i] != NULL)
            {
                cout << "Pr:  " << setw(14) << left << elements[j][i]->getInstructor();
            }
            else
            {
                cout << setw(19) << "";
            }  
        }

        cout << "|"<< endl;

    }
    cout << setfill('-');

    cout << setw(105) << "" << endl; 


}

void Schedule::clear()
{
    for (int i = 0; i < BAD_WEEK_DAY; i++)
    {
        
        for (int j = 0; j < BAD_TIME_SLOT; j++)
        {
            elements[i][j] = NULL;
        }
        

    }
}

string Schedule::getTerm()
{
    return term;
}


