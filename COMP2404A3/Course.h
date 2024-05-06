#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

/*
Purpose: Store data on courses for students to be assigned
Func:
- lessThan: is course less than given course

Var:
- nextID: id for the next course that is added

*/

class Course
{
    public:
        Course(string="", string="", int=0, char=' ',string="");
        ~Course();
        bool lessThan(Course*);
        void print();
        int getID();
        string getTerm();
        void getCID();

    private:
        static int nextID;
        int id;
        string term;
        string subject;
        int code;
        char section;
        string instructor;

};

#endif
