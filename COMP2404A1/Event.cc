#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Event.h"

Event::Event(int i, string eventName, string c, string part, int y, int m, int d, int h, int min)
{
    id = i;
    name = eventName;
    cat = c;
    num = 0;
    addParticipant(part);
    date.set(d,m,y);
    time.set(h,min);

}

int Event::getID()
{
    return id;
}

string Event::getCat()
{
    return cat;
}

Date Event::getDate()
{
    return date;
}

void Event::set(Event& e)
{

    id = e.id;
    name = e.name;
    cat = e.cat;
    date.set(e.date);
    time.set(e.time);
    num = 0;

    for (int i = 0; i < e.num; i++)
    {
        addParticipant(e.part[i]);

    }
    

}

void Event::addParticipant(string p)
{

    part[num] = p;
    num++;

}

bool Event::lessThan(Event& e)
{
    if (date.lessThan(e.date))
    {
        return true;
    }    
    else if (date.equals(e.date))
    {
        if (time.lessThan(e.time))
        {
            return true;
        }    
    }
    
    return false;

}

void Event::print()
{
    cout << setfill(' ');
    cout << "== " << id << "  " << setw(8) << left <<cat << ":: " << setw(32) << left << name << " :: ";
    time.print();
    cout << " @ ";
    date.print();
    cout << " with ";

    for (int i = 0; i < num; i++)
    {
        cout << part[i];
        
        if (i < num - 1)
        {
            cout << ", ";
        }
        
    }
    cout << endl;


}
