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

  cout << "Searching for ID not on ends of list." << endl;

  string mid = "1935";
  Student* middle = searchId(vect,mid,0,vect.size());

  if(middle != NULL)
  {
    cout << "\n +-------------------+ \n" << endl;
    cout << "Found Id " << mid << endl;
    middle->display();
    cout << "\n +-------------------+ \n" << endl;
   }

  /* Search for an ID on the left */

  cout << "Searching for ID on left end." << endl;

  string l = "588";
  Student* left = searchId(vect,l,0,vect.size());

  if(left != NULL)
  {
    cout << "\n +-------------------+ \n" << endl;
    cout << "Found Id " << l << endl;
    left->display();
    cout << "\n +-------------------+ \n" << endl;
   }

  /* Search for an ID on the right */

  cout << "Searching for ID on right end." << endl;

  string r = "32538";
  Student* right = searchId(vect,r,0,vect.size());

  if(right != NULL)
  {
    cout << "\n +-------------------+ \n" << endl;
    cout << "Found Id " << r << endl;
    right->display();
    cout << "\n +-------------------+ \n" << endl;
   }

  /* Search for an ID not in the list */

  cout << "Searching for ID not in list." << endl;

  string nothere = "3";
  Student* notin = searchId(vect,nothere,0,vect.size());

  if(notin != NULL)
  {
    cout << "\n +-------------------+ \n" << endl;
    cout << "Found Id " << nothere << endl;
    notin->display();
    cout << "\n +-------------------+ \n" << endl;
   }
  else
  {
    cout << "\n +-------------------+ \n" << endl;
    cout << "Id " << nothere << " not in vector." << endl;
    cout << "\n +-------------------+ \n" << endl;
   }

  /* Erase the students and vector to get rid of memleaks. */

  for(int i = 0 ; i < vect.size() ; i++)
  {
    delete vect[i];
  }

  vect.erase(vect.begin(),vect.end());

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

    /* The whole atoi(string.c_str()) is REALLY tacky. Should get around to 
       fixing that eventually */

    int mid = ((max+min)/2);

    if(atoi(list[mid]->getId().c_str()) > atoi(target.c_str()))
    {
      return searchId(list,target,min,mid-1);
    }
    else
    if(atoi(list[mid]->getId().c_str()) < atoi(target.c_str()))
    {
      return searchId(list,target,mid+1,max);
    }
    else
    {
      return list[mid];
    }

  }

}
