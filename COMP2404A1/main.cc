#include <iostream>
using namespace std;
#include <string>

#include "defs.h"
#include "Calendar.h"

/*
Author: Bruce Wong
Purpose: Make a calendar system that holds events for the user

1: View all events 
2: View all events with the given date
3: View all events with given category
4: Add event with what the user enters
0: Exit program

*/

int main()
{
  int choice = -1;
  int yr = 0,mth = 0,day = 0, hrs = 0, mins = 0;
  string cat = "";
  string part = "";
  string eventName = "";

  Calendar cal("Timmy Tortoise");

  loadEvents(cal);

  while (choice != 0)
  {
    showMenu(choice);

    if (choice == 1)
    {
      cal.print();
    }
    else if (choice == 2)
    {

      cout << "Please enter year, month, day:"; 

      cin >> yr >> mth >> day;

      cal.printByDay(yr,mth,day);
    }
    else if (choice == 3)
    {

      cout << "Please enter category: "; 

      cin >> cat;

      cal.printByCat(cat);

    }
    else if (choice == 4)
    {
      getchar(); 
      cout << "Please enter event name: ";
      getline(cin, eventName);

      cout << "Please enter category: ";
      cin >> cat;

      cout << "Please enter main participant: ";
      cin >> part;

      cout << "Please enter year, month, day:";
      cin >> yr >> mth >> day;
      
      cout << "Please enter hours, minutes: ";
      cin >> hrs >> mins;

      if (cal.addEvent(eventName, cat, part, yr, mth, day, hrs, mins))
      {
        cout << "SUCCESS: Event was added successfully";
      }
      else{
        cout << "ERROR: Event could not be added";
      }

    }

  }
  

  return 0;
}

void showMenu(int& choice)
{
 int numOptions = 4;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) View calendar" << endl;
  cout << "  (2) View day calendar" << endl;
  cout << "  (3) View category calendar" << endl;
  cout << "  (4) Add an event" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }


}

void loadEvents(Calendar& cal)
{
  cal.addEvent("2024 National Heroes Conference", "Work",  "Timmy", 2024,  2, 25,  8, 30);
  cal.addEvent("2023 National Heroes Conference", "Work",  "Timmy", 2023,  2, 24,  8, 30);
  cal.addEvent("Slay dragon",                     "Work",  "Timmy", 2024,  4, 11,  9, 30);
  cal.addEvent("Climb Mount of Dooom",            "Work",  "Timmy", 2024,  4,  8, 10,  0);
  cal.addEvent("some thing",                      "Work",  "Timmy", 2024,  3, 32, 10,  0);
  cal.addEvent("some other thing",                "Other", "Timmy", 2023,  2,  1, 24,  0);
  cal.addEvent("some new thing",                  "Test",  "Timmy", 2023,  2, 18, 14,  0);
  cal.addEvent("Lunch with Gwendolyn",            "Home",  "Timmy", 2024,  3, 29, 11, 45);
  cal.addEvent("Heroes meeting",                  "Work",  "Timmy", 2024,  1,  8,  9,  0);
  cal.addEvent("Practice sparring",               "Work",  "Timmy", 2024,  1, 10, 13, 45);
  cal.addEvent("Sharpen sword",                   "Work",  "Timmy", 2024,  1, 10, 13,  5);
  cal.addEvent("Dinner with Harold",              "Home",  "Timmy", 2024,  3, 30, 18, 30);
  cal.addEvent("Theatre with Harold",             "Home",  "Timmy", 2024,  3, 30, 16,  0);
  cal.addEvent("Grocery shopping",                "Home",  "Timmy", 2024,  1, 20,  9, 45);
  cal.addEvent("Meeting with Wizard",             "Work",  "Timmy", 2024,  3, 28,  6, 15);
  cal.addEvent("some bad thing",                  "Home",  "Timmy", 2023, 22, 18, 14,  0);

  cal.addParticipant(3012, "Harold");
  cal.addParticipant(3011, "Harold");
  cal.addParticipant(3004, "Harold");
  cal.addParticipant(3009, "Harold");
  cal.addParticipant(3004, "Dorc friends");
  cal.addParticipant(3003, "Harold");
  cal.addParticipant(3007, "Gwendolyn");
}

