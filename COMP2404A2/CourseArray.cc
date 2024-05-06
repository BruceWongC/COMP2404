#include <iostream>
using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray()
{
  size = 0;
}

CourseArray::~CourseArray()
{
  for (int i = 0; i < size; i++) {
    delete elements[i];
  }
}

void CourseArray::add(Course* c)
{
    if (size >= MAX_ARR) {
      return;
    }

    int counter = 0;
    for (int i = 0; i < size; i++)
    {
    
        if (elements[i]->lessThan(c))
        {
          break;
        }
        counter++;

    }

    for (int i = size; i > counter; i--)
    {
      elements[i] = elements[i - 1];
    }
    
    c->setID(COURSE_ID + size);
    elements[counter] = c;
    size++;
}

bool CourseArray::find(int id, Course** c)
{

    for (int i = 0; i < size; i++)
    {
        if (elements[i]->getID() == id)
        {
          *c = elements[i];
          return true;
        }
        
    }

    *c = NULL;
    return false;
    

}

void CourseArray::print(string s)
{

  for (int i = 0; i < size; i++) {
    if (elements[i]->getTerm() == s)
    {
      elements[i]->print();
    }
  }

}

