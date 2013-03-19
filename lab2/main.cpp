#include "stack_ll.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "../lab1/ll.h"

using namespace std;

void addFileToStack(ifstream&,stack_ll*);
void addFileToList(ifstream&,ll*);

int main(int argc, char *argv[])
{

  stack_ll* st = new stack_ll;
  ll* list = new ll;
  ifstream ifs;
  ifs.open("input.txt");

  cout << "\n\nAdding student objects to our linked list.\n\n";

  addFileToList(ifs, list);

  cout << "\n\nProceeding to push 5 students from list onto stack.\n\n";

  for(int i = 0; i < 5 ; i++)
  {
    Student* temp;
    temp = list->getStudent(i);
    st->push(temp);
  }

  cout << "\n\nPushing remaining students onto stack\n\n";

  for(int i = 5 ; i < 20 ; i++)
  {
    Student* temp;
    temp = list->getStudent(i);
    st->push(temp);
  }

  cout << "\n\nProceeding to pop all students off the stack\n\n";

  for(int i = 0 ; i < 20 ; i++)
  {
    Student* temp;
    temp = st->pop();
    temp->display();
    delete temp;
  }

  delete st;
  delete list; 
  return 0;

}

void addFileToStack(ifstream& input,stack_ll* sp)
{

  while( input.good() && input.peek() != EOF )
  {

    string id,name,address,gpastring;
    getline(input,id,';');
    getline(input,name,';');
    getline(input,address,';');
    getline(input,gpastring,'\n');

    double gpa;
    gpa = atof(gpastring.c_str());

    Student *temp = new Student(id,name,address,gpa);
    sp->push(temp);

  }

  /* Put ifs seeker back to beginning of file stream */
  input.seekg(0, ios::beg);

}

void addFileToList(ifstream& input,ll* list)
{

  while( input.good() && input.peek() != EOF )
  {

    string id,name,address,gpastring;
    getline(input,id,';');
    getline(input,name,';');
    getline(input,address,';');
    getline(input,gpastring,'\n');

    double gpa;
    gpa = atof(gpastring.c_str());

    Student *temp = new Student(id,name,address,gpa);
    list->insertTail(temp);

  }

  /* Put ifs seeker back to beginning of file stream */
  input.seekg(0, ios::beg);

}
