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

  cout << "\n\nDISPLAYING CONTENTS\n\n";

  list->displayContents();

  cout << "\n\nCONTENTS DISPLAYED\n\n";
  cout << "\n\nDELETING LIST ELEMENTS\n\n";

  delete list;

/*

  list->deleteListContents();

  cout << "\n\nLIST ELEMENTS DELETED\n\n";
  cout << "\n\nDISPLAYING CONTENTS\n\n";

  list->displayContents();
*/
//  list->displayContents();

//  cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

//  list->sortByName();
/*
  cout << "We will now delete the list. " << endl;

  delete list;

  cout << "List deleted." << endl;
*/
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

    Student *temp = new Student(id,name,address,gpa);
    list->insertTail(temp);

  }

  input.seekg(0, ios::beg);

}
