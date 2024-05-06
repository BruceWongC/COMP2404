#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

/*
Purpose: Hold name, number and program of STD

Func:
- lessThan: Check if name is less than name of given STD 

vars:
- name: name of STD
- number: STD number
- majorPgm: name of STD program

*/

class Student
{
    public:
        Student(string="",string="",string="");
        ~Student();
        bool lessThan(Student*);
        void print();
	    string getNumber();
	    string getName();
        
    private:
        string name;
        string number;
        string majorPgm;

};

#endif
