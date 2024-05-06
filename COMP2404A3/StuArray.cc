#include <iostream>
using namespace std;
#include "StuArray.h"

StuArray::StuArray()
{
    size = 0;
}

StuArray::~StuArray()
{
    for (int i=0; i<size; ++i) {
        delete elements[i];
    }
}

void StuArray::add(Student* s)
{
    if (size >= MAX_ARR) {
        return;
    }

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (elements[i]->lessThan(s))
        {
            break;
        }
        count++;
    }

    for (int i = size; i > count; i--)
    {
        elements[i] = elements[i - 1];
    }

    elements[count] = s;
    ++size;
}

bool StuArray::find(string num, Student** s)
{
    for (int i = 0; i < size; i++)
    {
        if (elements[i]->getNumber() == num)
        {
            *s = elements[i];
            return true;
        }
        
    }

    return false;    
}

void StuArray::print()
{

    for (int i = 0; i < size; i++)
    {
        elements[i]->print();
    }
    

}
