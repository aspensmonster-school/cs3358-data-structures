/* Doubly Linked List */

#include "queue.h"
#include <iostream>
#include <string>
#include <cstdlib>

#ifndef NULL
#define NULL 0
#endif

using namespace std;

queue::queue()
{
  head = NULL;
//  tail = NULL;
}

queue::~queue()
{
  cout << "Called queue destructor" << endl;
  deleteListContents();
  delete head;
//  delete tail;

}

void queue::insertTail(Student* stu)
{

  /* Test if empty list */
  if (head == NULL)
  {
    node *temp = new node;
    temp->student = stu;
    temp->next = NULL;
    head = temp;
    return;
  }

  /* add (first) to tail */
  else  
  if (head->next == NULL)
  {
    node *temp = new node;
    temp->student = stu;
    temp->next = NULL;
    head->next = temp;
    return; 
  }  

  /* add to tail */
  node *temp;
  temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }

  node *temp2 = new node;
  temp2->student = stu;
  temp2->next = NULL;
  temp->next = temp2;

  return;

}

/* Since head is front of list, we just return head and update accordingly */

Student* queue::pop(int index)
{
  node *temp;
  temp = head;

  if(temp == NULL)
  {
    cout << "List is empty. Can't return anything." << endl;
    exit(-1);
  }

  for(int i = 0 ; i < index ; i++)
  {
    if(temp->next == NULL)
      {
        break;
      }
    temp = temp->next;
  }

  Student* stu = temp->student;
  stu->display();
  return stu;

}


void queue::deleteListContents()
{
  
  cout << "Deleting list..." << endl;
 
  if(head == NULL)
  {
    cout << "Empty list. Nothing to delete." << endl;
    return;
    /* What if head get's set to NULL inappropriately? Then
     * memory still isn't free'd and we can't get to it!
     * Gotta make sure that doesn't happen.
     */
  }
 
  node *temp;

  while(head->next != NULL) 
  {
   
    temp = head->next;
    head->next = temp->next;
    delete temp;
    
  }

  cout << "Attempting to delete head... " << endl;

  delete head;
  head = NULL;
 
  cout << "Head deleted." << endl;
 
  /* Don't need to delete tail. We deleted its contents in the while loop
   * above
   */

//  tail = NULL;

}

