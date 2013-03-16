#ifndef stack_h_
#define stack_h_

#include "../student.h"

class stack

{

  private:

    static const int STACK_SIZE = 100;
    Student* stackarray[STACK_SIZE]; /* 100 stack frames oughta be enough for anybody... */
    int index;

  public:

    stack();
    virtual ~stack();

    void push(Student*);
    Student* pop();
    bool isEmpty();

};

#endif
