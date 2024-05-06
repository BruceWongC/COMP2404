#include "Escape.h"
#include "defs.h"
#include "List.h"
#include "Snorc.h"
#include "Ninja.h"

Escape::Escape()
{
  srand ((unsigned)time( NULL ) );

  int c1 = random(10) + 7;

  h1 = new Hero('T', 20, c1, "Timmy");

  int c2 = random(10) + 7;

  while (c1 == c2)
  {
      c2 = random(10) + 7;
  }

  h2 = new Hero('H', 20, c2, "Harold");    

  partList += h1; 
  partList += h2;
  
  numSnorcs = 0;

}

Escape::~Escape(){}

void Escape::runEscape()
{

  int num = 0;
  while (!isOver())
  {
    system("clear");
    printPit();
    
    moveParticipants();

    num = random(100);
    if (num < SNORC_SPAWN)
    {
      spawnSnorc();
    }

    num = random(100);
    if (num < NINJA_SPAWN)
    {
      spawnNinja();
    }
    usleep(100000);


  }
  system("clear");
  printPit();
  printOutcome();


}

bool Escape::isOver()
{
  if ((h1->getAvatar() == '+' || h1->getRow() == 1) && (h2->getAvatar() == '+' || h2->getRow() == 1))
  {
    return true;
  }

  return false;
  
}

bool Escape::withinBounds(int r, int c) 
{

    if (r < 1 || r > MAX_ROW)
    {
        return false;
    }

    if (c < 1 || c > MAX_COL - 1)
    {
        return false;
    }

    return true;
}

void Escape::spawnSnorc()
{
  if (numSnorcs == MAX_SNORCS)
  {
    return;
  }
  int strength = random(3) + 2;// 2 - 4 (inclusive), so 0 - 2 add 2 equals same

  int row = MAX_ROW - random(7);
  int col = random(MAX_COL - 1) + 1;

  Snorc* s = new Snorc(row, col, strength);

  partList += s;

  numSnorcs++;
}

void Escape::spawnNinja()
{

  int row = 3;
  int col = random(MAX_COL - 1) + 1;

  Ninja* n = new Ninja(row, col);

  partList += n;
}

Participant* Escape::checkForCollision(Participant* p)
{
  Participant* arr[MAX_ARR];
  int size = 0;

  partList.convertToArray(arr, size);

  for (int i = 0; i < size; i++)
  {
    
    if (arr[i] != p && arr[i]->getCol() == p->getCol() && arr[i]->getRow() == p->getRow())
    {
      return arr[i];
    }
    

  }
  
  return nullptr;

}

void Escape::moveParticipants()
{
  Participant* arr[MAX_ARR];
  int size = 0;


  partList.convertToArray(arr, size);

  for (int i = 0; i < size; i++)
  {
    if (arr[i]->isDead() || arr[i]->isSafe())
    {
      continue;
    }
    
    arr[i]->move();

    Participant* temp = checkForCollision(arr[i]);

    if (temp != nullptr)
    {
      arr[i]->incurDamage(temp);
      temp->incurDamage(arr[i]);
    }
  }
}

void Escape::printPit()
{

  char templateGrid[MAX_ROW+2][MAX_COL+2]={
      "--------------------------",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "|                        |",
      "--------------------------" 
  };

  Participant* arr[MAX_ARR];
  int size = 0;

  partList.convertToArray(arr, size);

  int row = 0;
  int col = 0;

  for (int i = 0; i < size; i++)
  {    
    if (arr[i]->isSafe())
    {
      continue;
    }

    row = arr[i]->getRow();
    col = arr[i]->getCol();

    if (row != 1 && templateGrid[row][col] != 'H' && templateGrid[row][col] != 'T' && templateGrid[row][col] != '+')
    {
        templateGrid[row][col] = arr[i]->getAvatar();
    }

  }
  
  for (int i = 0; i < MAX_ROW + 2; i++)
  {
    cout << templateGrid[i]; 

    if (i == MAX_ROW - 1)
    {
      cout << "     " << setw(6) << left << h1->getName() << ":  " << setw(2) << h1->getHealth();
      
      if (h1->getAvatar() == '+')
      {
        cout << "  Deceased";
      }            
      else if (h1->getRescue())
      {
        cout << "  Rescued";
      }

      else if (h1->isSafe())
      {
        cout << "  Escaped";
      }          
  }
  else if (i == MAX_ROW)
  {
      cout << "     " << setw(6) << left << h2->getName() << ":  " << setw(2) << h2->getHealth();
      
      if (h2->getAvatar() == '+')
      {
        cout << "  Deceased";
      }
      else if (h2->getRescue() == true)
      {
        cout << "  Rescued";
      }
      else if (h2->isSafe())
      {
        cout << "  Escaped";
      }
    }

    cout << endl;
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
    cout << h1->getName() <<" has died" << endl;
  }
  else
  {
    cout << h1->getName() <<" has escaped" << endl;
  }

  if (h2->getAvatar() == '+')
  {
    cout << h2->getName() <<" has died" << endl;
  }
  else
  {
    cout << h2->getName() << " has escaped" << endl;
  }  

  cout << endl;
}