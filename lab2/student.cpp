#include "student.h"
#include <string>
#include <iostream>

using namespace std;

Student::Student()
{

  id = "8675309";
  name = "Sir Hammerlock";
  address = "Southern Shelf";
  gpa = 2.0;

}

Student::Student(string id, string name, string address, double gpa)
{
  this->id = id;
  this->name = name;
  this->address = address;
  this->gpa = gpa;
}

Student::Student(const Student& copy)
{
  //
  id = copy.id;
  name = copy.name;
  address = copy.address;
  gpa = copy.gpa;
}

Student& Student::operator=(const Student& copy)
{
  //Self-assign check
  if(this == &copy)
  {
    return *this;
  }
 
  id = copy.id;
  name = copy.name;
  address = copy.address;
  gpa = copy.gpa;

  return *this;
  
}

Student::~Student()
{
//  cout << "Student destructor called." << endl;
}

void Student::display()
{
  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Address: " << address << endl;
  cout << "GPA: " << gpa << endl;
}

void setInfo(string id, string name, string address, double gpa)
{
  id = id;
  name = name;
  address = address;
  gpa = gpa;
}

/*
void Student::getInfo()
{
  cout << "getInfo() stub" << endl;
}
*/

void Student::setId(string id)
{
  id = id;
}

void Student::setName(string name)
{
  name = name;
}

void Student::setAddress(string address)
{
  address = address;
}

void Student::setGpa(double gpa)
{
  gpa = gpa;
}

string Student::getId()
{
  return id;
}

string Student::getName()
{
  return name; 
}

string Student::getAddress()
{
  return address;
}

double Student::getGpa()
{
  return gpa;
}
