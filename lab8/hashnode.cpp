#include "hashnode.h"

HashNode::HashNode()
{
  int key = -1;
  stu = NULL;
  next = NULL;
}

HashNode::~HashNode()
{
  if(flag)
  {
    delete stu;
  }
}

void HashNode::set(Student* student)
{

  if(key < 0)
  {
    key = atoi(student->getId().c_str());
    stu = student;
    next = NULL;
  }
  else
  {
    /* Create a new HashNode; this one is occupied */
 
    HashNode h;
    h.set(student); /* This will always hit the key < 0, since the HashNode
                     * constructor sets key to -1.
                     */

    /* Update next; it will follow the chain until it gets to the end, and 
     * add HashNode h to it
     */

    HashNode* temp = this;

    while(temp->next != NULL)
    {
      temp = temp->next;
    }

    temp->next = &h;
  }
}

void HashNode::unset()
{
  key = -1;
  stu = NULL;
  next = NULL;
}


