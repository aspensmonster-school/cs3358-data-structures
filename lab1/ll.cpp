/* Doubly Linked List */

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
//  tail = NULL;
}

ll::~ll()
{
  cout << "Called ll destructor" << endl;
  deleteListContents();
  delete head;
//  delete tail;

}

void ll::insertTail(Student* stu)
{

  /* Test if empty list */
  if (head == NULL)
  {
    node *temp = new node;
    temp->student = stu;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    //tail = temp;
    return;
  }

  /* add (first) to tail */
  else  
  if (head->next == NULL)
  {
    node *temp = new node;
    temp->student = stu;
    temp->next = NULL;
    temp->prev = head;
    head->next = temp;
    //tail = temp;
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
  temp2->prev = temp;
  temp2->next = NULL;
  temp->next = temp2;
  //tail = temp2;

  return;

}

void ll::insertHead(Student *stu)
{

  /* Test for empty list */  
  if (head == NULL)
  {
    node *temp = new node;
    temp->student = stu;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    //tail = temp;
    return;
  }

  /* If list isn't empty, do this */
  else
  {
    node *temp = new node;
    temp->student = stu;
    head->prev = temp;
    temp->next = head;
    temp->prev = NULL;
    head = temp;
  }

}

void ll::insert(Student* stu,int slot)
{

  /* Test if empty list */
  if (head == NULL)
  {
    cout << "List was empty. Creating head." << endl;
    node *temp = new node;
    temp->student = stu;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    //tail = temp;
    return;
  }

  if (slot == 1)
  {
    cout << "Slot " << slot << " is the head of the list." << endl;
    insertHead(stu);
    return;
  }

  /* Cycle through 'til we get to the slot */
  int i = 1;
  node *temp;
  temp = head;

  while(temp != NULL && i < slot)
  {
    i++;
    temp = temp->next;
  }

  /* temp is now pointing at the slot we wish to insert at ideally*/

  /* Test if the slot the user asked for exists */
  if( i < slot)
  {
    cout << "Don't have that many slots, adding to tail." << endl;
    insertTail(stu);
    return;
  }

  node *add = new node;
  add->student = stu;
  add->next = temp;
  add->prev = temp->prev; 

  /* Now update other elements */ 

  temp->prev->next = add;
  temp->prev = add; 

}

void ll::deleteListContents()
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

void ll::sortByName()
{

  cout << "Sorting Stub" << endl;

}

void ll::displayContents()
{

  node *temp;
  temp = head;
  
  cout << "Displaying..." << endl;  
  cout << "temp should be null after deletion... " << temp << endl;
 
  while(temp != NULL)
  {
    temp->student->display();
    temp = temp->next;
  }

  cout << "We've finished displayContents() " << endl;

}

