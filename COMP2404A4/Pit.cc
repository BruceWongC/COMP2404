#include "Hero.h"
#include "PartArray.h"
#include "Pit.h"

Pit::Pit(const char c[MAX_ROW + 1][MAX_COL + 1])
{
    for (int i = 0; i < MAX_ROW + 1; i++)
    {
        for (int j = 0; j < MAX_COL + 1; j++)
        {
            layout[i][j] = c[i][j]; 
        }
    }
}

Pit::~Pit() {}

bool Pit::withinBounds(int row, int col)
{
    if ((row <= 0 || row > MAX_ROW - 2) || (col < 0 || col >= MAX_COL))
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

bool Pit::validPos(int row, int col)
{
    if ((row <= 0 || row > MAX_ROW - 2) || (col < 0 || col >= MAX_COL))
    {
        return false;
    }
    else
    {
        return (layout[row][col] != '-');
    }
}

bool Pit::underLedge(Position* p)
{    
    return (layout[p->getRow() - 1][p->getCol()] == '-');    
}

void Pit::print(PartArray* p, Hero* h1, Hero* h2)
{
    char tempPit[MAX_ROW + 1][MAX_COL + 1];

    for (int i = 0; i < MAX_ROW + 1; i++)
    {
        for (int j = 0; j < MAX_COL + 1; j++)
        {
            tempPit[i][j] = layout[i][j]; 
        }
    }
    
    int row = 0;
    int col = 0;

    for (int i = 0; i < p->getSize(); i++)
    {
        col = p->get(i)->getCol();
        row = p->get(i)->getRow();        

        if (row != 1 && tempPit[row][col] != 'H'&& tempPit[row][col] != 'T' && tempPit[row][col] != '+')
        {
            tempPit[row][col] = p->get(i)->getAvatar();
        }
        

    }
    
    for (int i = 0; i < MAX_ROW + 1; i++)
    {
        for (int j = 0; j < MAX_COL + 1; j++)
        {
            cout << tempPit[i][j];
        }

        if (i == MAX_ROW - 2)
        {
            cout << "     " << setw(6) << left << h1->getName() << ":  " << h1->getHealth();
        }
        else if (i == MAX_ROW - 1)
        {
            cout << "     " << setw(6) << left << h2->getName() << ":  " << h2->getHealth();
        }
        
        
        cout << endl;
        
    }
    


}

