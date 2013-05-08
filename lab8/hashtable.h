#ifndef hashtable_h_
#define hashtable_h_

/* This implementation of the stack is a singly-linked list */

#include "../student.h"
#include "hashnode.h"

using namespace std;

class HashTable 

{

  private:

    HashNode table[SIZE];

  public:

    HashTable();
    virtual ~HashTable();

    void insert(Student*);
    Student* retrieve(int);
    void remove(int);

};

#endif
