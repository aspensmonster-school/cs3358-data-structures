#include "stack.h"
#include <cstdlib>
#include <iostream>

#ifndef NULL
#define NULL 0
#endif

using namespace std;

stack::stack()
{
  /* initialize our stack */
  for(int i = 0 ; i < STACK_SIZE ; i++)
  {
    stackarray[i] = NULL;
  }

  index = -1;
}

stack::~stack()
{
  for(int i = 0 ; i < STACK_SIZE ; i++)
  {
    delete stackarray[i];
  }

//  delete stackarray;

}

void stack::push(Student* stu)
{
  if(index == STACK_SIZE - 1)
  {
    cout << "There you go, trying to smash the stack..." << endl;
    return;
  }
  else
  {
    stackarray[++index] = stu;
  }
}

Student* stack::pop()
{
  if(index < 0)
  {
    cout << "Stack is empty. " << endl;
    exit(-1);
  }
  else
  {
    Student* temp;
    temp = stackarray[index]; 
    stackarray[index] = NULL;
    index--;
    return temp;
  }
}

bool stack::isEmpty()
{
  if(index < 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
