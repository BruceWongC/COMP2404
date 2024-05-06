#include "School.h"
#include <iostream>
using namespace std;

School::School(string n)
{

    name = n;

}

School::~School(){}

void School::addCourse(Course* c)
{

    arr.add(c);

}

bool School::findCourse(int i, Course** c)
{

    return arr.find(i , c);

}

void School::printCourses(string s)
{

    cout << endl << name << " FOR TERM " << s << endl;
    arr.print(s);

}