#ifndef ESCAPE_H
#define ESCAPE_H

#include "Participant.h"
#include "List.h"
#include "Hero.h"
#include "defs.h"

/*
Purpose: Main class that runs the code

Functions:
- runEscape: Main body that runs the program
- spawnSnorc: Dynamically spawn a snorc in list
- spawnNinja: Dynamically spawn a ninja in list
- moveParticipant: Move every participant in the list
- checkForCollision: Check for the first collision that isn't itself
- isOver: Check if the game should end
- printOutcome: Print the end results
- printPit: Prints the pit
- withinBounds: Is the inputs a valid cord for the pit

Variables:
- h1, h2: Hero 1 and Hero 2
- partList: List of participants
*/


class Escape
{
    public:
        Escape();
        ~Escape();
        void runEscape();
        static bool withinBounds(int, int);
        
    private:
        int numSnorcs;
        Hero* h1;
        Hero* h2;
        List<Participant*> partList;

        void spawnSnorc();
        void spawnNinja();
        void moveParticipants();
        Participant* checkForCollision(Participant*);
        bool isOver();
        void printPit();
        void printOutcome();

};

#endif
