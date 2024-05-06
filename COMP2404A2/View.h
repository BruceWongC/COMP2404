#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/*
Purpose: Provide user interface and get user input

Functions:
showmeau(): provides interface
read functions: read user input for str or int

*/

class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
