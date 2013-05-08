#include "hashnode.h"
#include <cstdlib>
#include <iostream>

HashNode::HashNode()
{
  key = -1;
  stu = NULL;
  next = NULL;
}

HashNode::~HashNode()
{

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
 
    HashNode* h = new HashNode();
    h->set(student); /* This will always hit the key < 0, since the HashNode
                     * constructor sets key to -1.
                     */

    /* Update next; it will follow the chain until it gets to the end, and 
     * add HashNode h to it
     */

/*

    HashNode* temp = this;

    while(temp->next != NULL)
    {
      temp = temp->next;
    }

    temp->next = &h;

*/
    cout << "Got a collision." << endl;
    cout << "Current key: " << key << endl;
    cout << "Next key: " << h->getKey() << endl;

    if(next == NULL)
    {
      next = h;
    }
    else
    {
      HashNode* temp = next;
      while(temp->getNext() != NULL)
      {
        temp = temp->getNext(); 
      }
      temp->setNext(h); 
    }

  }
}

void HashNode::unset()
{
  key = -1;
  stu = NULL;
  next = NULL;
}

int HashNode::getKey()
{
  return key;
}

Student* HashNode::getStudent()
{
  return stu;
}

HashNode* HashNode::getNext()
{
  return next;
}

void HashNode::setNext(HashNode* ptr)
{
  next = ptr;
}
