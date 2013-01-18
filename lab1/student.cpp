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
  id = id;
  name = name;
  address = address;
  gpa = gpa;
}

Student::~Student()
{

}

void Student::display()
{
  cout << "display stub." << endl;
}

void setInfo(string id, string name, string address, double gpa)
{
  id = id;
  name = name;
  address = address;
  gpa = gpa;
}

void Student::getInfo()
{
  cout << "getInfo() stub" << endl;
}

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
