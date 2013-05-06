/* Need to get input from user that has the data for all of the students. Ought
   to use input file. Easier to parse and grab from command line.
*/

#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "../student.h"

using namespace std;

void addFileToList(ifstream&,list<Student*>&)

int main(int argc, char *argv[])
{

  list<Student*> list;
  ifstream ifs;
  ifs.open("input.txt");
  addFileToList(ifs, list);

  cout << "\n\nDISPLAYING CONTENTS\n\n";

  

  cout << "\n\nCONTENTS DISPLAYED\n\n";
  cout << "\n\nDELETING LIST ELEMENTS\n\n";

  list->deleteListContents();
  list->deleteListContents();

  for(int i = 0; i < 2 ; i++)
  {
    addFileToList(ifs, list);
  }

  list->displayContents();
  
  list->deleteListContents();
  list->deleteListContents();
  list->deleteListContents();

  cout << "Putting insert() through its paces." << endl;

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

  cout << "Completed insertion paces." << endl;

  list->deleteListContents();

  cout << "New list made. Attempting to sort." << endl;

  addFileToList(ifs, list); 

  cout << "Beginning list sort." << endl;

  list->sortById();

  cout << "List (supposedly) sorted." << endl;

  list->displayContents();

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

void addFileToList(ifstream& input,list<Student*>& list)
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
    list.push_back(temp);

    /* Now add grades to the student */

    bool flag = true;

    while(flag)
    {
      string stringgrade;
      double tempgrade;

      getline(input,stringgrade,';');
      tempgrade = atof(stringgrade.c_str());

      /* See if we've reached the last grade yet */
      if(input.peek() == '\n')
      {
        flag = false;
        input.get();
        /* Need to get \n char so next outer while iteration works */
      }

      temp->addGrade(tempgrade);
    }

  }

  /* Put ifs seeker back to beginning of file stream */
  input.seekg(0, ios::beg);

}

