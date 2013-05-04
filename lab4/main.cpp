#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "../student.h"

using namespace std;

void addFileToVector(ifstream&,vector<Student*>&);
Student* searchId(vector<Student*>&,string,int,int);

int main(int argc, char *argv[])
{

  ifstream ifs;
  ifs.open("input-sorted.txt");
  vector<Student*> vect;

  cout << "\n\nAdding student objects to our vector.\n\n";

  addFileToVector(ifs, vect);

  /*Display all Student Records*/
  for(int i = 0; i < vect.size() ; i++)
  {
    vect[i]->display();
    cout << "\n ============================ \n";
  }

  /* Search for an ID not on the ends */

  string mid = "1935";
  Student* middle = searchId(vect,mid,0,vect.size());

  cout << middle << endl; 
 
  if(middle != NULL)
  {
    cout << "Found Id " << mid << endl;
    middle->display();
  }

  /* Search for an ID on the left */

  /* Search for an ID on the right */

  /* Search for an ID not in the list */

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

Student* searchId(vector<Student*>& list, string target, int min, int max)
{
 
  if(max < min)
  {
    return NULL;
  }
  else 
  {

    int mid = ((max-min)/2);

    if(list[mid]->getId() > target)
    {
      return searchId(list,target,min,mid-1);
    }
    else
    if(list[mid]->getId() < target)
    {
      return searchId(list,target,mid+1,max);
    }
    else
    {
      return list[mid];
    }

  }

}
