#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student(string num, string n, string p)
{
    name = n;
    number = num;
    majorPgm = p;
}

Student::~Student(){}

bool Student::lessThan(Student* s)
{
    return (name > s->name);
}

void Student::print()
{

    cout << setw(11) << left << number << setw(11) << name << majorPgm << endl;

}

string Student::getNumber()
{
    return number;
}

string Student::getName()
{
    return name;
}
