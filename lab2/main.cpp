/* Need to get input from user that has the data for all of the students. Ought
   to use input file. Easier to parse and grab from command line.
*/

#include "stack.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void addFileToList(ifstream&,stack*);

int main(int argc, char *argv[])
{

  stack* st = new stack;
  ifstream ifs;
  ifs.open("input.txt");
  addFileToList(ifs, st);

  cout << "test." << endl;

  return 0;

}

void addFileToList(ifstream& input,stack* st)
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
//    list->insertTail(temp);
    st->push(temp);

  }

  /* Put ifs seeker back to beginning of file stream */
  input.seekg(0, ios::beg);

}
