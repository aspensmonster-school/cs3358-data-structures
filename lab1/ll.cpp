/* First implementation of linked list. Buggy. Only an idiot would use this. */

#include "ll.h"

#ifndef NULL
#define NULL 0
#endif

ll::ll()
{
  head = NULL;
}

ll::~ll()
{

}

void ll::addtail(int data)
{
  /* Test if empty list */

  if (head == NULL)
  {
    node *temp = new node;
    //temp->someValue = data;
    temp->next = NULL;
    head = temp;
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
  //temp2->someValue = data;
  temp2->next = NULL;

  temp->next = temp2;
  return;
}
