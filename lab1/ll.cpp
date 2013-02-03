/* Doubly Linked List */

/* Turning into doubly linked list. */

#include "ll.h"
#include <iostream>
#include <string>

#ifndef NULL
#define NULL 0
#endif

using namespace std;

ll::ll()
{
  head = NULL;
  tail = NULL;
}

ll::~ll()
{
  delete head;
  delete tail;
}

void ll::insertTail(Student* stu)
{

  /* Test if empty list */
  if (head == NULL)
  {
    node *temp = new node;
    //temp->someValue = data;
    temp->student = stu;
    //temp->student.display();
    temp->next = NULL;
    head = temp;
    return;
  }

  /* add (first) to tail */
  
  if (head->next == NULL)
  {
    node *temp = new node;
    temp->student = stu;
    temp->next = NULL;
    head->next = temp;
    //temp->student.display();
//    delete temp;
    return; 
  }  

  /* add to tail */

  node *temp = new node;
  temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }

  node *temp2 = new node;
  temp2->student = stu;
  temp2->next = NULL;
  //temp2->student.display();  

  temp->next = temp2;

//  delete temp;
//  delete temp2;

  return;

}

void ll::deleteListContents()
{
    
//  node *temp;
//  temp = head;

    while(head->next != NULL)
    {
     
      node *temp = new node; 
      temp = head->next;
      cout << "temp is: " << temp << endl;
      cout << "head->next is: " << head->next << endl;
      head->next = temp->next;
      cout << "Deleting temp" << endl;
      delete temp;
      cout << "Success." << endl;
    
    }

  delete head;
  head = NULL;

}

void ll::sortByName()
{
  /* There's a bunch of different ways of going about this */

  /* Check that we don't have an empty list */ 
  if(head == NULL)
  {
    return;
  }

  /* Carry on otherwise */

  node *oldhead = new node;
  oldhead = head;
  node *lowest = new node;
  lowest = head;
  node *index = new node;
  index = head;

  /* Establish the head of our sorted list */
  while(index->next != NULL)
  {
    string name1 = index->student->getName(); 
    string name2 = index->next->student->getName();
      
    if (name1.compare(name2) < 0)
    {
      /* name1 comes before name2, like it should */
      //index->next = index->next->next; /* <-- This is why you're wrong */
      index = index->next;
    }
    else
    if (name1.compare(name2) > 0)
    {
      /* name1 comes after name2, need to swap the lowest eventually */
      lowest = index->next;
      //index->next = index->next->next; /* <-- This is why you're wrong */ 
      index = index->next;
    }
    head = lowest;
  }

  cout << "FOUND LOWEST" << endl;
//  head->student.display();
//  lowest->student.display();
//  oldhead->student.display();
//  cout << &oldhead << endl;
//  cout << oldhead << endl;
//  cout << &(oldhead->next) << endl;
//  oldhead->next->student.display();
//  oldhead->next->next->student.display();
  /* Prep for rest of next pointer updating */
  index = oldhead->next; 
//  cout << "1" << endl;
  //oldhead->next = oldhead->next->next;
//  cout << "2" << endl;
  lowest = index;
//  cout << "3" << endl;
  node *worker = new node;
//  cout << "4" << endl;
  worker = head;

  cout << "BEGINNING SORT" << endl;

  /*Establish the new pointers for a sorted list*/
  while(index != NULL)
  {

    while(index->next != NULL)   
    {

      if(index->next == lowest)
      {
        /* well... shit. I don't think this is gonna work. */
      }

      string name1 = index->student->getName();  
      string name2 = index->next->student->getName();
      
      if (name1.compare(name2) < 0)
      {
        /* name1 comes before name2, like it should */
        //index->next = index->next->next;
        index = index->next;
      }
      else
      if (name1.compare(name2) > 0)
      {
        /* name1 comes after name2, need to swap the lowest eventually */
        lowest = index->next;
        //index->next = index->next->next;  
        index = index->next;
      }
      cout << "LOL COMPARE" << endl;
    }

    worker->next = lowest;
    worker = worker->next;

    //index = oldhead->next;
    index = oldhead->next;
    //oldhead->next = oldhead->next->next;  
    oldhead = oldhead->next;
    lowest = index;

    cout << "FINISHED AN ITERATION OF SORT" << endl;
 
  }

  cout << "DONE SORT" << endl;

  delete lowest;
  delete index;
  delete worker;
  delete oldhead;
}

void ll::displayContents()
{
  node *temp = new node;
  temp = head;
  
  while(temp != NULL)
  {
    temp->student->display();
    temp = temp->next;
  }

  delete temp;

}

