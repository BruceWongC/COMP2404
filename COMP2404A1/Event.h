#ifndef EVENT_H
#define EVENT_H
#include <string>
#include "Time.h"
#include "Date.h"
#include "defs.h"
using namespace std;

/*
Purpose: Event that will be collected by a calendar object

Event: Constructor
set: Sets values of Event object with the given Event object
addParticipant: Add person to the array of participants
lessThan: Does Event happen before given the Event or not 
*/

class Event
{
  public:
    Event(int=0,string="",string="",string="",int=0,int=0,int=0,int=0,int=0);
    void set(Event&);
    int getID();
    string getCat();
    Date getDate();
    void addParticipant(string);
    bool lessThan(Event& e);
    void print();

  private:
    int id;
    int num;
    string name;
    string cat;
    Time time;
    Date date;
    string part[MAX_PART];

};

#endif
