#include "stack.h"

#ifndef NULL
#define NULL 0
#endif

#include<iostream>

using namespace std;

stack::stack()
{
  /* initialize our stack */
  for(int i = 0 ; i < 100 ; i++)
  {
    stackarray[i] = NULL;
  }

}

stack::~stack()
{
  for(int i = 0 ; i < 100 ; i++)
  {
    delete stackarray[i];
  }

//  delete stackarray;

}

void stack::push(Student* stu)
{

  int i = 0;

  while( stackarray[i] != NULL && i < 100)
  {
    i++;
  }

  if(i == 100)
  {
    cout << "There you go, trying to smash the stack..." << endl;
    return;
  }

  stackarray[i] = stu;
}

Student* stack::pop()
{
  int i = 0;

  while(stackarray[i] != NULL)
  {
    i++;
  }

  Student* temp;
  i--;
  temp = stackarray[i];
  stackarray[i] = NULL;

  return temp;

}

bool stack::isEmpty()
{
  if(stackarray[0] == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}
