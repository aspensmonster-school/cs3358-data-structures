#include <vector>
#include "../student.h"
#include <cstdlib>

using namespace std;

quicksort::quicksort()
{
  /* Nothing to do here for now. Just refactoring atm. */
}

quicksort::~quicksort()
{
  /* Ditto */
}

void sort(vector<Student*>& list, int left, int right)
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
    sort(list, left, max);
  }
  if(min < right)
  {
    sort(list, min, right);
  }

}
