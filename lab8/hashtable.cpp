#include "hashtable.h"
#include "hashnode.h"
#include <cstdlib>
#include <iostream>

HashTable::HashTable()
{
  for(int i = 0; i < 101; i++)
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
  int index = hash(key);
  
  HashNode* temp = &table[index];

  while(temp->getKey() != key)
  {
    temp = temp->getNext(); 
  }

  return temp->getStudent();
 
}

void HashTable::remove(int key)
{
  int index = hash(key);

  HashNode* follow = &table[index];
  HashNode* lead = follow->getNext();

  /* Case 1: There is nothing in this index at all */

  if(follow->getKey() < 0)
  {
    //cout << "Nothing to delete dummy." << endl;
    return; /* Nothing at this index. supplied key is not in table */
  }

  /* Case 2: There is only one node at this index */

  if(lead == NULL && follow->getKey() == key)
  {
    //cout << "Single node. Unsetting it." << endl;
    follow->unset(); 
    return;
  }
  else
  if(follow->getKey() != key)
  {
    //cout << "Single node. Wrong key. Leaving as is." << endl;
    return; /* There's a single node in the index, and this isn't the one */
  }

  /* Case 3: There are two or more nodes at this index */  

  /* Subcase 1: remove first node */

  if(follow->getKey() == key)
  {
    //cout << "Attempting to delete first node." << endl;
    table[index] = *lead;

    return;
    //delete follow;
    //You don't delete things off the stack, Preston.
  }

  /* Ok. We're not removing the first node. Let's find the node we are 
   * removing (if it's in the list).
   */

  while(lead->getKey() != key && lead->getNext() != NULL)
  {
    follow = lead;
    lead = lead->getNext();
  }

  /* Now, the node we're getting rid of is either somewhere in the middle 
   * or at the end. We'll know if it's at the end because temp2 will be null
   */

  /* Subcase 2: end of list */

  if(lead->getNext() == NULL && lead->getKey() == key)
  {
    delete lead;
    follow->setNext(NULL);
    return;
  }
  else
  if(lead->getKey() != key)
  {
    return; /* We're at the end and haven't found the node */
  }
  

  /* Subcase 3: middle of list */

  /* We know that lead has hit a match thanks to the while loop above */

  follow->setNext(lead->getNext());
  delete lead; 

}

void HashTable::showState()
{
  for(int i = 0 ; i < 101 ; i++)
  {
    if(table[i].getKey() < 0)
    {
      continue;
    }
    else
    {
      HashNode* temp = &table[i];
      int j = 0;
      while(temp != NULL)
      {
        //cout << "temp ptr val: " << temp << endl;
        cout << "Row " << i << " column " << j << " key " << temp->getKey();
        cout << endl; 
        j++;
        temp = temp->getNext();
      }
    }
  } 
}
