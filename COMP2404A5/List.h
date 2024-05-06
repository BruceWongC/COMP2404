#ifndef LIST_H
#define LIST_H
#include <iostream>

/*
Purpose: Linkedlist that holds the collection of participant pointers using templates

Functions:
- operator+=: add participant pointer to end of list 
- convertToArray: take all items in list and put them into an array

*/


template <class T>
class List
{
  class Node
  {
    public:
      T* data;
      Node*    next;
  };

  public:
    List();
    ~List();
    List& operator+=(T); 
    void convertToArray(T*,int&);

  private:
    Node* head;
};

template <class T>
List<T>::List() : head(nullptr) { }

template <class T>
List<T>::~List()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete *(currNode->data);
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T> 
List<T>& List<T>::operator+=(T newData) 
{
  Node* newNode = new Node(); 
  newNode->data = new T;
  *(newNode->data) = newData;
  newNode->next = nullptr;
       
  if (head == nullptr)
  {
    head = newNode;
  }
  else
  {
    Node* currNode = head;
    
    while (currNode->next != nullptr) {
      currNode = currNode->next;
    }
    
    currNode->next = newNode;
  }
  
  return *this;
}

template <class T>
void List<T>::convertToArray(T* arr, int& size)
{
    Node* currNode = head;

    while (currNode != nullptr)
    {              
      arr[size++] = *(currNode->data);
      currNode = currNode->next;
    }

}

#endif
