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

  list->deleteListContents();
  
  cout << "\n\nPutting insert() through its paces.\n\n" << endl;

  Student* empty = new Student();
  list->insert(empty,10);

  list->deleteListContents();

  addFileToList(ifs, list);

  Student* newhead = new Student();
  list->insert(newhead,1);

  Student* middle = new Student();
  list->insert(middle,6);

  /* TODO: if the user inserts the same Student object into the list
   * multiple times, the program segfaults because two nodes are ref-
   * erencing the same memory spot. So when we go to delete the second
   * instance in the list a la `delete foo` the program barfs because
   * we're trying to delete memory that's already deleted!
   */

  Student* farout = new Student();
  list->insert(farout,100);

  cout << "\n\nCompleted insertion paces.\n\n" << endl;

  list->deleteListContents();

  addFileToList(ifs,list);

  cout << "\n\nMaking new list that will then be sorted.\n\n" << endl;

  list->displayContents();

  cout << "\n\nBeginning list sort.\n\n" << endl;

  list->sortById();

  cout << "\n\nList sorted.\n\n" << endl;

  list->displayContents();

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

    Student *temp = new Student(id,name,address,gpa);
//    list->insertTail(temp);
    list->insertHead(temp);

  }

  /* Put ifs seeker back to beginning of file stream */
  input.seekg(0, ios::beg);

}
