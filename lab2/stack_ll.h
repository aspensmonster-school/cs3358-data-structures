#ifndef stack_ll_h_
#define stack_ll_h_

/* This implementation of the stack is a singly-linked list */

#include "../student.h"
#include <iostream>

using namespace std;

class stack_ll

{

  private:

    struct node {
      Student *student;
      node *next;
      ~node(){delete student;} 
    };
    node *head;
//    node *tail;

  public:

    stack_ll();
    virtual ~stack_ll();

    void push(Student*);
    Student* pop();
    void deleteStackContents();

};

#endif
