#include <iostream>
using namespace std;
#include "CourseArray.h"

CourseArray::CourseArray()
{
    size = 0;
}

CourseArray::~CourseArray()
{
    for (int i=0; i<size; ++i) {
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

    elements[counter] = c;
    size++;
}

bool CourseArray::find(int i, Course** c)
{
    for (int j = 0; j < size; j++)
    {
        if (elements[j]->getID() == i)
        {
            *c = elements[j];
            return true;
        }
        
    }

    return false;    
}

void CourseArray::print()
{
    for (int i = 0; i < size; i++)
    {
        elements[i]->print();
    }
}

void CourseArray::print(string term)
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i]->getTerm() == term)
        {
            elements[i]->print();
        }
        
        
    }
}
