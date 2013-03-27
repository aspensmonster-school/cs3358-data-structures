#include <iostream> /*cout*/
#include <deque> /*Double Ended Queue Container*/
#include <unistd.h> /*usleep()*/
#include <cstdlib> /*system()*/

using namespace std;

void prepare(int, deque< deque<int> >&);
void render(int, deque< deque<int> >&,bool);
void towersOfHanoi(int,int,int,int,int, deque< deque<int> >&);

int main(int argc, char *argv[])
{

  deque< deque<int> > stax;
  prepare(3,stax);
  system("clear");

  cout << "Performing Towers of Hanoi for 3 discs." << endl; 

  usleep(2000000);

  /* 3 is height, 3 is number of discs, 0 is tower A, 2 is tower C, and 1 is tower B */
  render(3,stax,true);
  towersOfHanoi(3,3,0,2,1,stax);

  usleep(2000000);
  system("clear");

  cout << "Performing Towers of Hanoi for 4 discs." << endl;

  usleep(2000000);

  prepare(4,stax);
  render(4,stax,true);
  towersOfHanoi(4,4,0,2,1,stax);

  usleep(2000000);
  system("clear");

  cout << "Peforming Towers of Hanoi for 5 discs." << endl;

  usleep(2000000);

  prepare(5,stax);
  render(5,stax,true);
  towersOfHanoi(5,5,0,2,1,stax);

  return 0;

}

/* Initializes our vector of vectors */
void prepare(int height, deque< deque<int> >& _stax)
{

  _stax.erase(_stax.begin(),_stax.end());
  _stax.resize(3);

  /*Filling 0 (tower A) with discs */
  for(int i = 0 ; i < height ; i++)
  {
    _stax[0].push_back(i);
  }
  
}

/* Renders the state of our deque of deque's */
void render(int height, deque< deque<int> >& _stax,bool refresh)
{
  /* OS-dependent. Use "cls" if you're on windows. */
  if ( refresh )
  {
    system("clear");
  }

  int layer = 0;
  bool finished = false;

  /* Display indentifier bar */
  cout << "A:" << "\t" << "B:" << "\t" << "C:" << endl << endl;

  /* We do the following to make sure we have the same overall height 
     with each rendering */

  int greatest = 0;

  for(int i = 0 ; i < 3 ; i++)
  {
    if(_stax[i].size() > greatest)
    {
      greatest = _stax[i].size();
    }
  }

  while( greatest < height )
  {
    cout << endl;
    greatest++;
  }

  /*Now that we have gotten the rendering box right, onto rendering*/

  while( !finished )
  {

    int count = 0;

    for(int i = 0 ; i < 3 ; i++)
    {
      if( _stax[i].size() > layer)
      {
        cout << _stax[i][layer] << "\t";
      }
      else
      {
        cout << "\t";
        count++;
      }
    }

    layer++;

    if(count == 3)
    {
      finished = true;
      cout << endl << "=================" << endl;
    }
    else
    {
      cout << endl;
    }

  }

  /* Sleep for a second */
  usleep(1000000); /* usleep takes microseconds */

}

/* Implements the recursive solution */
void towersOfHanoi(int height, int disc, int start, int finish, int scratch, deque< deque<int> >& _stax)
{
  if(disc == 1)
  {
    _stax[finish].push_front(_stax[start].front());
    _stax[start].pop_front();
    render(height,_stax,true);
  }
  else
  {
    towersOfHanoi(height, disc - 1, start, scratch, finish, _stax);
    _stax[finish].push_front(_stax[start].front());
    _stax[start].pop_front();
    render(height,_stax,true);
    towersOfHanoi(height, disc - 1, scratch, finish, start, _stax);     
  } 
}
