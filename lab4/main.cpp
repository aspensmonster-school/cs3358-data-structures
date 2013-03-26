#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "../student.h"

using namespace std;

void addFileToVector(ifstream&,vector<Student*>&);

int main(int argc, char *argv[])
{

  ifstream ifs;
  ifs.open("input.txt");
  vector<Student*> vect;

  cout << "\n\nAdding student objects to our vector.\n\n";

  addFileToVector(ifs, vect);

  return 0;

}

void addFileToVector(ifstream& input,vector<Student*>& vec)
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
    vec.push_back(temp);

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
