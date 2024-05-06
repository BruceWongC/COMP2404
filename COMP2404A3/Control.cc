#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control()
{
  s = new School("Carleton U, School of Computer Science");
}

Control::~Control()
{
  delete s;
}

void Control::launch()
{
  initStudents(s);
  initCourses(s);

  int choice = -1;
  string stuNum = "";
  Student* stu;
  Course* cou;
  string term = "";
  int id = 0;

  while (choice != 0)
  {
    v.showAdminMenu(choice);
  
    if (choice == 1)
    {
      s->printStudents();
    }
    else if (choice == 2)
    {
      s->printCourses();
    }
    else if (choice == 3)
    {
      s->printRegistrations();
    }
    else if (choice == 4)
    {
      cout << "Please enter student number: ";
      v.readStr(stuNum);
      
      while (!s->findStudent(stuNum, &stu))
      {
        cout << "ERROR: Student number not found, please try again: ";
        v.readStr(stuNum);
      }
      
      while (choice != 0)
      {
        v.showStudentMenu(stu->getName(),choice);
      
        if (choice == 1)
        {
          cout << "Please enter term: ";
          v.readStr(term);
          s->printCourseByTerm(term);
        }
        else if (choice == 2)
        {
          s->printRegistrationsByStu(stu);
        }
        else if (choice == 3)
        {
          cout << "Please enter course id: ";
          v.readInt(id);

          if (s->findCourse(id, &cou))
          {
            s->addRegistration(stu, cou);
          }
          else
          {
            cout << "ERROR: Course not found";
          }
          
        }      
      }
      
      choice = -1;//set back to a default num
    }
    
  
  }
  




}


void Control::initStudents(School* sch)
{
  sch->addStu(new Student("100567888", "Matilda", "CS"));
  sch->addStu(new Student("100333444", "Harold", "Geography"));
  sch->addStu(new Student("100444555", "Joe", "Physics"));
  sch->addStu(new Student("100775588", "Timmy", "CS"));
  sch->addStu(new Student("100111222", "Amy", "Math"));
  sch->addStu(new Student("100222333", "Stanley", "Art History"));
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen"));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill"));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill"));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel"));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin"));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill"));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI"));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier"));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp"));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel"));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel"));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill"));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill"));
}


