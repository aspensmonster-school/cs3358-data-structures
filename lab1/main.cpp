/* Need to get input from user that has the data for all of the students. Ought
   to use input file. Easier to parse and grab from command line.
*/

#include "ll.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void addFileToList(ifstream&,ll*);

int main(int argc, char *argv[])
{

  ll* list = new ll;
  ifstream ifs;
  ifs.open("input.txt"); 
  addFileToList(ifs, list); 
  delete list;
  return 0;

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

    Student temp(id,name,address,gpa);
    list->addtail(temp);

    cout << "=====================================================" << endl;

  }

  input.seekg(0, ios::beg);

}
