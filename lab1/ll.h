#ifndef ll_h_
#define ll_h_

#include "student.h"

class ll

{

  private:

    struct node {
      Student student;
      node *next;
      node *prev;
      ~node(){delete next; delete prev;}
    };
    node *head;
    node *tail;

  public:

    ll();
    virtual ~ll();

    void insertTail(Student);
    void insertHead(Student);
    void insert(Student,int);
    void insert(Student);

    void removeTail();
    void removeHead();
    void remove(int);
    void remove();
    
    void sortByName();
    void displayContents();

};

#endif
