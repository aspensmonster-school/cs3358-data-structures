/* Doubly Linked List */

#include "ll.h"
#include <iostream>
#include <string>
#include <cstdlib>

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

  cout << "Sort-by-name Stub" << endl;

}

void ll::sortById()
{

  if(head == NULL)
  {
    cout << "Empty list. Nothing to sort." << endl;
    return;
  }
  else
  if(head->next == NULL)
  {
    cout << "Single item. Sorted by default." << endl;
    return;
  }

  node* i;
  node* l;
  node* p;

  i = head;
  l = i;
  p = i->next;  

  short flag = 0; 

  while(p != NULL)
  {
   
    string temp1 = i->student->getId();
    int temp1i = atoi(temp1.c_str());

    cout << "We're entering the loop." << endl;

    while(p != NULL)
    {
      string temp2 = p->student->getId(); 
      int temp2i = atoi(temp2.c_str());
      string temp3 = l->student->getId();
      int temp3i = atoi(temp3.c_str());

      if(temp2i < temp1i && temp2i < temp3i)
      {
        cout << temp2i << " is lower than " << temp1i << " and " << temp3i << endl;
        l = p;
      }

      p = p->next;
    }

    cout << "We've escaped the loop." << endl;

    if(flag == 0)
    {
      head = l;
      flag++;
    }

    /* If l and i are right next to each other, then l->prev->next breaks.
     * Heck, if i and l are equal, this breaks.
     */

    /* i IS l ; this iteration is already sorted. Carry on.*/
    if(l == i)
    {
      cout << "i is lowest" << endl;
      i = i->next;
      l = i;
      p = i->next;
      continue;
    }

    /* l and i right next to each other */
    if(l->prev == i && ( l->student->getId() < l->prev->student->getId() ))
    {
      cout << "i and l are next to each other." << endl;
      cout << "Apparently " << l->student->getId() << " is less than " << l->prev->student->getId() << "." << endl;
      
      if(l->next != NULL)
      {
        l->next->prev = i;
      }

      if(i->prev != NULL)
      {
        i->prev->next = l;
      }

      /* Forgot about adding iteration code */
      node* nextIndex;
      nextIndex = i->next;

      i->next = l->next;
      l->next = i;

      node* iprev;
      iprev = i->prev;

      i->prev = l;
      l->prev = iprev;

      /* Forgot to include iteration in this case */

      i = nextIndex;
      l = i;
      p = i->next;

      continue;
    }

    /* l and i are separated by at least one node */
    
    l->prev->next = i;
    
    if(l->next != NULL)
    {
      l->next->prev = i;
    }
    
    if(i->prev != NULL)
    {
      i->prev->next = l;
    }
    i->next->prev = l;

    node* t1;
    node* t2;

    t1 = l->next;
    t2 = l->prev;

    l->next = i->next;
    l->prev = i->prev;

    node* nextIndex;
    nextIndex = i->next;

    i->next = t1;
    i->prev = t2;

    i = nextIndex;
    l = i;
    p = i->next;

    cout << "Lol looping." << endl;

  }

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

Student* ll::getStudent(int index)
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

//  Student* temp1 = temp->student;
  Student temp2;
//  temp2 = *temp1;
  temp2 = *(temp->student);
  Student* temp3 = new Student(temp2);
//  stu->display();
  return temp3;

  /* Should this be returing a copy to the caller only, or should it
     also remove its copy of the Student object from the list? */

  /* I could code for both cases with a bool flag parameter that indicates
     whether or not this is a "transfer." */

}

