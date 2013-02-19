#include "stack.h"

#ifndef NULL
#define NULL 0
#endif

using namespace std;

stack::stack()
{
  /* initialize our stack */

  for(int i = 0 ; i < 100 ; i++)
  {
    st[i] = NULL;
  }

}

stack::~stack()
{
  for(int i = 0 ; i < 100 ; i++)
  {
    delete st[i];
  }
}

void stack::push(Student* stu)
{
  int i = 0;

  while( st[i] != NULL && i < 100)
  {
    i++;
  }

  if(i == 100)
  {
    cout << "There you go, trying to smash the stack..." << endl;
    return;
  }

  st[i] = stu;

}

Student* stack::pop()
{
  int i = 0;

  while(st[i] != NULL)
  {
    i++;
  }

  Student* temp;
  temp = st[--i];
  st[i] = NULL;
  return temp;

}
