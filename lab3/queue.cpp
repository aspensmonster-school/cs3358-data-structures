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
  deleteQueueContents();
  delete head;
//  delete tail;

}

void queue::push(Student* stu)
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

Student* queue::pop()
{
  node *temp;
  temp = head;

  if(temp == NULL)
  {
    cout << "Queue is empty. Can't return anything." << endl;
    exit(-1);
  }

  head = head->next;

  Student stu = *(temp->student);
  Student* stu2 = new Student(stu);
  
  delete temp;

  return stu2;

}


void queue::deleteQueueContents()
{
  
  cout << "Deleting queue..." << endl;
 
  if(head == NULL)
  {
    cout << "Empty queue. Nothing to delete." << endl;
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

