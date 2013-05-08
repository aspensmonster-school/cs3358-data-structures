#include "hashtable.h"
#include <cstdlib>

HashTable::HashTable()
{
  for(int i = 0; i < 100; i++)
  {
    HashNode h;
    table[i] = h;
  }
}

HashTable::~HashTable()
{

}

int HashTable::hash(int key)
{
  int index = key % 101;
  return index;
}

void HashTable::insert(Student* student)
{
  int key = atoi(student->getId().c_str());
  int index = hash(key);
  table[index].set(student);
}

Student* HashTable::retrieve(int key)
{
  int index = hash(id);
  
  HashNode* temp = &table[index];

  while(temp->getKey() != key)
  {
    temp = temp->getNext(); 
  }

  return temp->getStudent();
 
}

void HashTable::remove(int key)
{
  int index = hash(id);

  HashNode* temp = &table[index];
  HashNode* temp2 = temp->getNext();

  /* Case 1: There is nothing in this index at all */

  if(temp->getKey() < 0)
  {
    return; /* Nothing at this index. supplied key is not in table */
  }

  /* Case 2: There is only one node at this index */

  if(temp2 == NULL)
  {
    temp->unset(); 
    return;
  }

  /* Case 3: There are multiple nodes at this index */  

  /* Subcase 1: remove first node */

  /* Subcase 2: remove middle node */

  /* Subcase 3: remove end node */

  if(temp->getKey() == key)
  {
    temp->set(temp2->getStudent()); 
    delete temp2;
  }

  while(temp2->getNext() != NULL)
  {
    temp = temp2;
    temp2 = temp2->getNext();
  } 

}
