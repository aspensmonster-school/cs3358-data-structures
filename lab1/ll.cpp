/* First implementation of linked list. Buggy. Only an idiot would use this. */

#include "ll.h"
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

using namespace std;

ll::ll()
{
  head = NULL;
}

ll::~ll()
{

}

void ll::addtail(Student stu)
{
  /* Test if empty list */

  if (head == NULL)
  {
    node *temp = new node;
    //temp->someValue = data;
    temp->student = stu;
    temp->student.display();
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
    temp->student.display();
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
  temp2->student.display();  

  temp->next = temp2;
  return;


}

void ll::getHead()
{
  cout << head << endl;
}
