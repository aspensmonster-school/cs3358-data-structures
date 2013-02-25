#ifndef stack_h_
#define stack_h_

#include "student.h"

class stack

{

  private:

    Student* stackarray[100]; /* 100 stack frames oughta be enough for anybody... */

  public:

    stack();
    virtual ~stack();

    void push(Student*);
    Student* pop();

};

#endif
