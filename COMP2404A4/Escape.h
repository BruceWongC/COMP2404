#ifndef ESCAPE_H
#define ESCAPE_H

#include "PartArray.h"

/*
Purpose: Main class that runs the code

Func:
- runEscape: Main body that runs the program
- spawnSnorc: Dynamically spawn a snorc in array
- moveParticipant: Move every participant in array
- checkForCollision: Check for the first collision that isn't itself
- isOver: Check if the game should end
- printOutcome: Print the end results

*/


class Escape
{
  public:
    Escape();
    ~Escape();
    void runEscape();

  private:
    int numSnorcs;
    PartArray part;
    Pit* pit;
    Hero* h1;
    Hero* h2;

    void spawnSnorc();
    void moveParticipant();
    Participant* checkForCollision(Participant*);
    bool isOver();
    void printOutcome();

};

#endif

