#include <iostream>
using namespace std;
#include <string>

#include "Escape.h"
#include "defs.h"
#include "Hero.h"
#include "Snorc.h"

Escape::Escape()
{
  const char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "-             --        -",
      "-                      --",
      "-       --              -",
      "                  --    -",
      "--       -              -",
      "---                    --",
      "---       --          ---",
      "--                     --",
      "-            --        --",
      "---               --     ",
      "--        --    ---    --",
      "--  --                  -",
      "--        --       -     ",
      "--                  -    ",
      "--     --         --    -",
      "---                    --",
      "--       ---    --      -",
      "--                     --",
      "-------------------------" 
  };

  srand( (unsigned)time( NULL ) );

  pit = new Pit(templateGrid);

  numSnorcs = 0;

  int col1 = random(10) + COL_BUFFER;
  int col2 = random(10) + COL_BUFFER;
  
  while (col1 == col2) 
  {
    col2 = random(10) + COL_BUFFER;
  }

  h1 = new Hero('T', MAX_ROW - ROW_BUFFER, col1, "Timmy");
  h2 = new Hero('H', MAX_ROW - ROW_BUFFER, col2, "Harold");

  part.add(h1);
  part.add(h2);
}

Escape::~Escape()
{
  delete pit;
}

void Escape::runEscape()
{
  int num = 0;
  while (!isOver())
  {
    system("clear");

    pit->print(&part,h1,h2); 

    moveParticipant();

    num = random(100);
    if (num < SNORC_SPAWN)
    {
      spawnSnorc();
    }

    usleep(100000);
  }
  system("clear");

  pit->print(&part,h1,h2); 

  printOutcome();

}

bool Escape::isOver()
{
  if ((h1->getAvatar() == '+' || h1->getRow() == 1)&& (h2->getAvatar() == '+' || h2->getRow() == 1))
  {
    return true;
  }

  return false;
  
}

void Escape::spawnSnorc()
{
  if (numSnorcs == MAX_SNORCS)
  {
    return;
  }
  int strength = random(3) + 2;// 2 - 4 (inclusive), so 0 - 2 add 2 equals same

  int row = MAX_ROW - random(5) - ROW_BUFFER;
  int col = random(MAX_COL);

  Snorc* s = new Snorc(row, col, strength);

  part.add(s);

  numSnorcs++;
}

Participant* Escape::checkForCollision(Participant* p)
{

  for (int i = 0; i < part.getSize(); i++)
  {
    if (part.get(i)->collide(p) && part.get(i) != p)
    {
      return part.get(i);
    }
    
  }
  
  return NULL;

}

void Escape::moveParticipant()
{

  for (int i = 0; i < part.getSize(); i++)
  {
    if (part.get(i)->getRow() > 1)
    {
      part.get(i)->move(pit);
    }
    
    Participant* temp = checkForCollision(part.get(i));
    if (temp != NULL)
    {
      part.get(i)->incurDamage(temp);
      temp->incurDamage(part.get(i));
    }
    

  }
}

void Escape::printOutcome()
{

  if (h1->getAvatar() == 'T' && h2->getAvatar() == 'H')
  {
    cout << "BOTH HEROS HAVE ESCAPED !!!" << endl;

    return;
  }
  else if (h1->getAvatar() == '+' && h2->getAvatar() == '+')
  {
    cout << "Both heros have died ..." << endl;

    return;
  }

  if (h1->getAvatar() == '+')
  {
    cout << "Timmy has died" << endl;
  }
  else
  {
    cout << "Timmy has escaped" << endl;
  }

  if (h2->getAvatar() == '+')
  {
    cout << "Harold has died" << endl;
  }
  else
  {
    cout << "Harold has escaped" << endl;
  }  

  cout << endl;
}



