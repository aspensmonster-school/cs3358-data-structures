/* This will be the student object */

#include <string>

class Student

{

  private:

    std::string id;
    std::string name;
    std::string address;
    double gpa;

  public:

    Student();
    Student(string,string,string,double);
    virtual ~Student();
    
    void display();

    /* The rubric calls for an "APPEND" function. Not sure exactly what we
       would be "appending" to a student object. Editing perhaps, but not
       appending.
    */

    void setInfo(string,string,string,double);
    void getInfo();

    void setId(string);
    void setName(string);
    void setAddress(string);
    void setGpa(double);

    void getId();
    void getName();
    void getAddress();
    void getGpa();

}    
