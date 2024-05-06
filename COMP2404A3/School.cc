#include "School.h"
#include <iostream>

School::School(string s)
{
    name = s;
}

School::~School()
{
    list.cleanData();
}

void School::addStu(Student* s)
{
    stuArr.add(s);
}

void School::addCourse(Course* c)
{
    courseArr.add(c);
}

void School::addRegistration(Student* s, Course* c)
{
    Registration* r = new Registration(s,c);
    list.add(r);
}

bool School::findStudent(string num, Student** s)
{
    return stuArr.find(num,s);
}

bool School::findCourse(int id, Course** c)
{
    return courseArr.find(id, c);
}

void School::printStudents()
{
    cout << endl << "STUDENTS OF " << name << endl;
    stuArr.print();
}

void School::printCourses()
{
    cout << endl << "COURSES OF " << name << endl;
    courseArr.print();
}

void School::printCourseByTerm(string term)
{
    cout << endl << "COURSES OF " << name << endl;
    courseArr.print(term);
}

void School::printRegistrations()
{
    cout << endl << "REGISTRATIONS OF " << name << endl;
    list.print();
}

void School::printRegistrationsByStu(Student* s)
{
    cout << endl << "REGISTRATIONS OF " << name << endl;
    RegList r(list,s);

    r.print();
}


