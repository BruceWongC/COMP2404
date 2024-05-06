#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;

/*
Purpose: GUI for user to see
Func:
- showAdminMenu: admin menu
- showStudentMenu: std menu
*/

class View
{
  public:
    void showAdminMenu(int&);
    void showStudentMenu(string, int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
