#ifndef SCHOOL_H
#define SCHOOL_H

#include "CourseArray.h"
#include "StuArray.h"
#include "RegList.h"

/*
Purpose: Hold arr of students, courses and the list of reistractions
Func:
- add...: add item to it's correct place
- find...: find item with given index then "return" it in the 2nd param
- print ...: print all items of array or list
- print ... by ...: print items with certain conditions

var:
- stuArr: array of std
- courseArr: array of courses
- list: linkedlist of regs

*/

class School
{
  public:
	  School(string="");
    ~School();
    //add functions
    void addStu(Student*);
    void addCourse(Course*);
    void addRegistration(Student*, Course*);
    //find functions
    bool findStudent(string, Student**);
    bool findCourse(int, Course**);
    //print functions
    void printStudents();
    void printCourses();
    void printRegistrations();
    //print funcions by something
    void printCourseByTerm(string);
    void printRegistrationsByStu(Student*);

  private:
    string name;
    StuArray stuArr;
    CourseArray courseArr;
    RegList list;

};

#endif

