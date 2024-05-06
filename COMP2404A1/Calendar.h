#ifndef CALENDER_H
#define CALENDER_H
#include <string>
#include "Time.h"
#include "Date.h"
#include "Event.h"

using namespace std;

/*
Purpose: Manages the number of events that the user adds or would like to view

Functions:
Calendar: Constructor
addEvent: Adds event that the user inputs
addParticipant: Adds person to a list in event

Var:
numEvents: Tracks the number of events
arr: Array of events
nextID: ID of events
*/

class Calendar
{
public:
    Calendar(string="");
    bool addEvent(string,string,string,int,int,int,int,int);
    bool addParticipant(int, string); 
    void print();
    void printByDay(int, int, int);
    void printByCat(string);

private:
    string name;
    int numEvents;
    Event arr[MAX_ARR];
    int nextID;


};


#endif

