#include <iostream>
using namespace std;
#include <string>
#include "Control.h"
#include "View.h"

Control::Control()
{
  ptr = new School("Carleton U. School of Computer Science");
  numScheds = 0;
}

Control::~Control()
{
  delete ptr;

  for (int i = 0; i < numScheds; i++)
  {
    delete arr[i];
  }
  
}

bool Control::addSched(Schedule* s)
{
  if(numScheds == MAX_ARR){
    return false;
  }

  arr[numScheds] = s;
  numScheds++;
  return true;

}

bool Control::findSched(string str, Schedule** s)
{

  for (int i = 0; i < numScheds; i++)
  {
    if (s[i]->getTerm() == str)
    {
      return true;
    }
  }
  
  return false;

}

void Control::launch()
{  

  int choice = -1;
  int n = -1;
  string term = "NONE SELECTED";
  View v;
  initCourses(ptr);

  while (choice != 0)
  {
    cout << endl << endl << "TERM: " << term;
    v.showMenu(choice);

    if (choice == 1)
    {
      
      cout << "Please enter new term: ";
      v.readStr(term);
      if(!findSched(term, arr))
      {
        addSched(new Schedule(term));
      }

    }
    else if (choice == 2)
    {
      
      ptr->printCourses(term);

    }
    else if (choice == 3)
    {

      if (findSched(term, arr))
      {
        for (int i = 0; i < numScheds; i++)
        {
          if (arr[i]->getTerm() == term)
          {
            arr[i]->print();
            break;
          }
        }
      }
      else{
        cout << endl << "ERROR:  No term selected";
      }
    }
    else if (choice == 4)
    {
      if (findSched(term, arr))
      {
        
        cout << "Please enter course id: ";
        v.readInt(n);
        Course* c;
        if (ptr->findCourse(n,&c))
        {
          for (int i = 0; i < numScheds; i++)
          {
            if (arr[i]->getTerm() == c->getTerm())
            {
              arr[i]->addCourse(c);
              break;
            }
          }
        }
        else
        {
          cout << endl << "ERROR: Course not found";
        }
      }
      else{
        cout << endl << "ERROR:  No term selected";
      }

    }
    else if (choice == 5)
    {
      if (findSched(term, arr))
      {

        for (int i = 0; i < numScheds; i++)
        {
          if (arr[i]->getTerm() == term)
          {
            arr[i]->clear();
            break;
          }
        }

      }
      else{
        cout << endl << "ERROR:  No term selected";
      }
    }
  }
}


void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau", TUE_THU, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen", WED_FRI, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau", MON_WED, 13, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen", TUE_THU, 8, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet", TUE_THU, 11, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet", MON_WED, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill", MON_WED, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill", MON_WED, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel", TUE_THU, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet", TUE_THU, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin", TUE_THU, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill", MON_WED, 8, 30));


  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI", MON_WED, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp", WED_FRI, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp", TUE_THU, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau", TUE_THU, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau", MON_WED, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel", TUE_THU, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel", MON_WED, 18, 0));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill", TUE_THU, 8, 30));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill", WED_FRI, 16, 0));
}

