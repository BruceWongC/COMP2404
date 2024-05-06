#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Calendar.h"

Calendar::Calendar(string s)
{
 
    name = s;
    nextID = EVENTS_ID;
    numEvents = 0;

}

bool Calendar::addEvent(string n, string cat, string part, int yr, int mth, int day, int hrs, int mins)
{
    int counter = 0; 

    if (numEvents == MAX_ARR)
    {
        cout << "Error: Cannot add more events" << endl;
        return false;
    }
    else if (!(Date().validate(day, mth, yr)))
    {
        cout << "Error: date " << yr << ", " << mth << ", " << day << " is invalid"  << endl;
        return false;
    }
    else if (!(Time().validate(hrs, mins)))
    {
        cout << "Error: time " << hrs << ", " << mins << " is invalid"  << endl;
        return false;
    }

    Event Ev(nextID + numEvents, n, cat, part, yr, mth, day, hrs, mins);

    for (int i = 0; i < numEvents; i++)
    {
        if (arr[i].lessThan(Ev))
        {
            counter++;
        }
        else
        {
            break;
        }
    }

    for (int i = numEvents; i > counter; i--)
    {
        arr[i].set(arr[i - 1]);
    }

    numEvents++;
    arr[counter].set(Ev);

    return true;

}

bool Calendar::addParticipant(int id, string n)
{
    for (int i = 0; i < numEvents; i++)
    {
        if (arr[i].getID() == id)
        {
            arr[i].addParticipant(n);
            return true;
        }
        
    }
    return false;
} 

void Calendar::print()
{
    cout << "Calendar for " << name << endl;
    for (int i = 0; i < numEvents; i++)
    {
        arr[i].print();
    }
    

}

void Calendar::printByDay(int yr, int mth, int day)
{
    if (!(Date().validate(day, mth, yr)))
    {
        cout << "Error: date is invalid";
        return;
    }
    
    Date temp(day,mth,yr);

    cout << "Calendar for " << name << " on ";
    temp.print();
    cout << endl;

    for (int i = 0; i < numEvents; i++)
    {
        if (arr[i].getDate().equals(temp))
        {
            arr[i].print();
        }
           
    }

}

void Calendar::printByCat(string cat)
{

    cout << endl << cat << " calendar for " << name << endl;

    for (int i = 0; i < numEvents; i++)
    {
        if (arr[i].getCat() == cat)
        {
            arr[i].print();
        }
        
    }
    
}

