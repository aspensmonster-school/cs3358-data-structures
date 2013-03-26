#include "queue.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "../lab1/ll.h"
#include <vector>

using namespace std;

void addFileToVector(ifstream&,vector);

int main(int argc, char *argv[])
{

  ifstream ifs;
  ifs.open("input.txt");

  cout << "\n\nAdding student objects to our vector.\n\n";

  addFileToVector(ifs, vect);

  /* Need to flesh all this out; refresh my memory on vectors. */

  return 0;

}

void addFileToVector(ifstream& input,vector vec)
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
