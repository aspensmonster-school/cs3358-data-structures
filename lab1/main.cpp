/* Need to get input from user that has the data for all of the students. Ought
   to use input file. Easier to parse and grab from command line.
*/

#include "ll.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  ll list;
  string id = "123";
  string name = "Bob Whatshisface";
  string address = "123 Fake St";
  double gpa = 3.0;
  list.getHead();
  Student bob(id,name,address,gpa);
//  Student bob;
  list.addtail(bob);
  list.getHead();
  Student jane;
  list.addtail(jane);
  list.getHead();
  list.addtail(jane);
  list.addtail(jane);
  return 0;
}
