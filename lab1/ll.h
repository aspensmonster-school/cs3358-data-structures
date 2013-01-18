#ifndef ll_h_
#define ll_h_

#include "student.h"

class ll

{

  private:

    struct node {
      Student student;
      node *next;
    };
    node *head;

  public:

    ll();
    virtual ~ll();

    void addtail(Student);
    void deltail(); 
};

#endif
