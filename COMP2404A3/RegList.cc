#include <iostream>
using namespace std;

#include "RegList.h"

RegList::RegList() : head(nullptr), tail(nullptr){ }

RegList::RegList(RegList& otherList, Student* stu) : RegList()
{

    Node* currNode = otherList.head;

    while (currNode != nullptr)
    {
        if (currNode->data->getStu() == stu)
        {
            Node* newNode = new Node();
            newNode->data = currNode->data;
            newNode->next = nullptr;
            if (head == nullptr)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        currNode = currNode->next;
    }
}

RegList::~RegList() 
{
  Node* currNode = head;
  Node* nextNode = nullptr;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

void RegList::add(Registration* r)
{
    Node* newNode = new Node();
    newNode->data = r;
    newNode->next = nullptr;
  
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        
        return;
    }

    Node* currNode = head;//head here will never be nullptr
    Node* prevNode = nullptr; 

    while (currNode != nullptr)
    {
        if (currNode->data->lessThan(r))
        {

            break;    
        }

        prevNode = currNode;
        currNode = currNode->next;
        
    }

    if (currNode == head)//if node was head
    {
        newNode->next = currNode;
        head = newNode;

    }
    else if (currNode != nullptr)//node was in middle
    {
        newNode->next = currNode;
        prevNode->next = newNode;

    }
    else //node was at the end
    {
        prevNode->next = newNode;
        tail = newNode;
    }


}

void RegList::cleanData()
{

    Node* currNode = head;

    while (currNode != nullptr)
    {
        delete currNode->data;
        currNode = currNode->next;
    }
    
}

void RegList::print() const
{
    Node* currNode = head;
    while (currNode != nullptr)
    {
        currNode->data->print();
        currNode = currNode->next;
    }

    if (head != nullptr)
    {
        cout << "HEAD: ";
        head->data->print();
        cout << "TAIL: ";
        tail->data->print();
    }
    else
    {
        cout << "HEAD: " << endl;
        cout << "TAIL: " << endl;

    }

}