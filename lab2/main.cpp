#include "stack.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void addFileToStack(ifstream&,stack*);

int main(int argc, char *argv[])
{

  stack* st = new stack;
  ifstream ifs;
  ifs.open("input.txt");

  cout << "\n\nPushing input file onto stack.\n\n";

  addFileToStack(ifs, st);

  cout << "\n\nPopping 5 students from the stack\n\n";

  for(int i = 0; i < 5 ; i++)
  {
    Student* temp;
    temp = st->pop();
    temp->display();
    delete temp;
  }

  cout << "\n\nPopping the remaining students from the stack\n\n";

  for(int i = 0 ; i < 20 ; i++)
  {
    if(st->isEmpty())
    {
      continue;
    }
    Student *temp;
    temp = st->pop();
    temp->display();
    delete temp;
  }
 
  delete st;
 
  return 0;

}

void addFileToStack(ifstream& input,stack* sp)
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
