/* Doubly Linked List */

#include "stack_ll.h"
#include <iostream>
#include <string>
#include <cstdlib>

#ifndef NULL
#define NULL 0
#endif

using namespace std;

stack_ll::stack_ll()
{
  head = NULL;
//  tail = NULL;
}

stack_ll::~stack_ll()
{
  cout << "Called stack_ll destructor" << endl;
  deleteStackContents();
  delete head;
//  delete tail;

}

void stack_ll::push(Student* stu)
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

Student* stack_ll::pop()
{

  node *temp;
  temp = head;

  /* newtop will hold a pointer to the new top of the stack */
  node *newtop;
  newtop = NULL;

  /* Empty list check */
  if(temp == NULL)
  {
    cout << "List is empty. Can't return anything." << endl;
    exit(-1);
  }

  /* Find the top of the stack */
  while(temp->next != NULL)
  {
    newtop = temp;
    temp = temp->next;
  }

  /* We are returning a pointer to a copy of the top of the stack */
  /* In this case, we return temp3 */
  Student temp2;
  temp2 = *(temp->student);
  Student* temp3 = new Student(temp2);

  /* So long as there is more than one element in stack, this is evaluated */
  if(newtop != NULL)
  {
    newtop->next = NULL; /* Make sure new top of stack's ->next is NULL */
  }
  else
  {
    head = newtop; /* newtop is NULL here; we've popped the last element */
  }

  /* We now delete the top of the stack */
  delete temp;

  /* And here we actually return our copy (non-const, so is manipulable)*/
  return temp3;

}

void stack_ll::deleteStackContents()
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
