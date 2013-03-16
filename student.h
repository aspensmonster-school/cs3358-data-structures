#ifndef student_h_
#define student_h_

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
    Student(std::string,std::string,std::string,double);
    virtual ~Student();
    Student(const Student&);
    Student& operator=(const Student&);
    
    void display();

    /* The rubric calls for an "APPEND" function. Not sure exactly what we
       would be "appending" to a student object. Editing perhaps, but not
       appending.
    */

    void setInfo(std::string,std::string,std::string,double);
    //This won't actually work atm...
    //void getInfo();

    void setId(std::string);
    void setName(std::string);
    void setAddress(std::string);
    void setGpa(double);

    std::string getId();
    std::string getName();
    std::string getAddress();
    double getGpa();

};

#endif
