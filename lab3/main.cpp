#include "queue.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "../lab1/ll.h"

using namespace std;

void addFileToQueue(ifstream&,queue*);
void addFileToList(ifstream&,ll*);

int main(int argc, char *argv[])
{

  queue* q = new queue;
  ll* list = new ll;
  ifstream ifs;
  ifs.open("input.txt");

  cout << "\n\nAdding student objects to our linked list.\n\n";

  addFileToList(ifs, list);

  cout << "\n\nProceeding to push 5 students from list onto queue.\n\n";

  for(int i = 0; i < 5 ; i++)
  {
    Student* temp;
    temp = list->getStudent(i);
    q->push(temp);
  }

  cout << "\n\nNow we are popping those five students.\n\n";

  for(int i = 0; i < 5 ; i++)
  {
    Student* temp;
    temp = q->pop();
    temp->display();
    delete temp;
  }

  delete q;
  delete list; 
  return 0;

}

void addFileToQueue(ifstream& input,queue* qlocal)
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
    qlocal->push(temp);

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
