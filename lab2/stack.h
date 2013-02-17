#ifndef stack_h_
#define stack_h_

#include "Student.h"

class stack

{

  private:

    Student* stack[100]; /* 100 stack frames oughta be enough for anybody... */

  public:

    stack();
    virtual ~stack();

    void push(Student*);
    void pop(Student*);

}

#endif
