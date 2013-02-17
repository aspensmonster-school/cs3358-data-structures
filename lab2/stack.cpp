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

}

void stack::pop(Student* stu)
{

}
