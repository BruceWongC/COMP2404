#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "View.h"

/*
Purpose: Controls the programs control flow
Func: 
- launch: starts main program
- initStudents: inits students to school
- initCourses: inits courses to school

Var:
- v: View class to use
- s: school that holds students, courses and reg

*/

class Control
{
	public:
		Control();
		~Control();
		void launch();
	private:
		void initStudents(School*);
    	void initCourses(School*);
		View v;
		School* s;

};

#endif
