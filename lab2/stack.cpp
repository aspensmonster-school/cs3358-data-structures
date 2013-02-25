#include "stack.h"

#ifndef NULL
#define NULL 0
#endif

#include<iostream>

using namespace std;

stack::stack()
{
  /* initialize our stack */
  cout << "initializing stack object" << endl;
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

  delete stackarray;

}

void stack::push(Student* stu)
{

  cout << "Inside push method" << endl;
 
  int i = 0;

  while( stackarray[i] != NULL && i < 100)
  {
    cout << i << endl;
    i++;
  }

  if(i == 100)
  {
    cout << "There you go, trying to smash the stack..." << endl;
    return;
  }

  stackarray[i] = stu;
  cout << "student object pushed onto stack" << endl;
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

  cout << "Popping student from stack." << endl;

  return temp;

}
