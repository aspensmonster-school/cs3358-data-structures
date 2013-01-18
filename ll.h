#ifndef ll_h_
#define ll_h_

class ll

{

  private:

    struct node {
      int someValue;
      node *next;
    };
    node *head;

  public:

    ll();
    virtual ~ll();

    void addtail(int);
    void deltail(); 

};

#endif
