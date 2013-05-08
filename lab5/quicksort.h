#ifndef quicksort_h_
#define quicksort_h_

#include <vector>
#include "../student.h"

class quicksort
{
  public:

  quicksort();
  virtual ~quicksort();

  void sort(vector<Student*>&,int,int);

}

#endif
