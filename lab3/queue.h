#ifndef queue_h_
#define queue_h_

#include "../student.h"
#include <iostream>

using namespace std;

class queue

{

  private:

    struct node {
      Student *student;
      node *next;
      ~node(){delete student;} 
    };
    node *head;

  public:

    queue();
    virtual ~queue();

    void push(Student*);
    Student* pop();
    void deleteQueueContents();

};

#endif
