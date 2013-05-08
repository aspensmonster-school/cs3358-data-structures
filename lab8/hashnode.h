#include "../student.h"

using namespace std;

class HashNode

{

  private:

    int key;
    Student* stu;
    HashNode* next;

  public:

    HashNode(Student*);
    virtual ~HashNode(bool); /* flag will instruct whether to delete Student
                              * object or just the node
                              */
    int getKey();
    Student* getStudent();

};
