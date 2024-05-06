#ifndef REGLIST_H
#define REGLIST_H

#include "Registration.h"

/*
Purpose: Linkedlist for registractions
Class Node: nodes for the linkedlist. Contains data and next node

Func: 
- RegList: ctor to make linkedlist with what's in given RegList for std
- add: add reg
- cleanData: clean data within linkist

Var:
- head: head of linkedlist
- tail: end of linkedlist

*/

class RegList
{
  class Node
  {
    public:
      Registration* data;
      Node*    next;
  };

  public:
    RegList();
    RegList(RegList&, Student*);
    ~RegList();
    void add(Registration*);
    void cleanData();
    void print() const;

  private:
    Node* head;
    Node* tail;

};

#endif