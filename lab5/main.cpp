#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "../student.h"

using namespace std;

void addFileToVector(ifstream&,vector<Student*>&);
void quickSort(vector<Student*>&,int,int);

int main(int argc, char *argv[])
{

  ifstream ifs;
  ifs.open("input.txt");
  vector<Student*> vect;

  cout << "\n\nAdding student objects to our vector.\n\n";

  addFileToVector(ifs, vect);

  /*Display all Student Records*/

  for(int i = 0; i < vect.size() ; i++)
  {
    vect[i]->display();
    cout << "\n ============================ \n";
  }

  /* Sort the vector via quicksort algorithm */

  cout << "\n\nProceeding to Quicksort\n\n";

  quickSort(vect,0,vect.size()-1);

  cout << "\n\nList should be sorted now\n\n";

  /* Display sorted list */

  for(int i = 0; i < vect.size() ; i++)
  {
    vect[i]->display();
    cout << "\n ============================ \n";
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

/*
 * Because plaigarism is bad, this is what I based this algo off of:
 * http://www.algolist.net/Algorithms/Sorting/Quicksort
 * Thought it was simpler than having to write another rebuilder function, 
 * even if doing it that way is more elegant.
 *
 * ALSO: This is NOT an in-place implementation.
 *
 */

 /* While quicksort averages nlog(n), it has no way of knowing how 
  * "well-sorted" a list may already be. It still has to partition through,
  * Doing lots of comparisons, even if the list is completely sorted.
  */

void quickSort(vector<Student*>& list, int left, int right)
{

  int min = left;
  int max = right;
  int pivot = atoi(list[(min+max)/2]->getId().c_str());

  /*Start partitioning*/
  while( min <= max )
  {
    /*find a value left of pivot that is NOT less than pivot so we can swap */
    while( atoi(list[min]->getId().c_str()) < pivot )
    {
      min++;
    }
    /*find a value right of pivot that is NOT more than pivot so we can swap */
    while( atoi(list[max]->getId().c_str()) > pivot )
    {
      max--;
    }
    /*We might have a pair that is swappable. Let's check */
    if( min <= max )
    {
      /* Yep. Swappable. Swap time. */
      Student* temp;
      temp = list[min];
      list[min] = list[max];
      list[max] = temp;
      min++;
      max--;
      /* Note: If the two elements are equal (Same pointer, not just same ID)
       * I wonder if my copy constructor will work correctly. Not sure how to 
       * go about testing that, though I think it should work since I check
       * for self-assign.
       */
    }

  } 

  /* Partitions Sorted Around Pivot. Repeat. */
  if(left < max)
  {
    quickSort(list, left, max);
  }
  if(min < right)
  {
    quickSort(list, min, right);
  } 

}
