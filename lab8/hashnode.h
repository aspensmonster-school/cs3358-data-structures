#include "../student.h"

using namespace std;

class HashNode

{

  private:

    int key;
    Student* stu;
    HashNode* next;

  public:

    HashNode();
    virtual ~HashNode(); 

    void set(Student*);
    void unset();

    int getKey();
    Student* getStudent();
    HashNode* getNext();
    void setNext(HashNode*);

};
