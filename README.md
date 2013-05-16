# Future Plans

Dated: Wed May 15 2013 2331 CST

I intend to enhance this portfolio over the summer, with an emphasis on 
exploring all of the features of C++ and the STL. Particularly, I'd like to 
investigate templatized versions of data structures (i.e., re-implement vector 
and the like as a learning experience).

I also intend to clone these efforts with C in a separate repository, 
exploring C's specific features and using C to write custom allocators and the 
like.

# About

Homework assignments for data structures class at Texas State University.
Professor requires use of C++ or Java. I'd prefer to use C so that I can learn 
it simultaneously, but specs are specs. Each lab assignment's focus is held in 
respective folders. Linked list implementation is in lab1, stacks in lab2, 
queues in lab3, binary searches in lab4, etc. Common objects are held in the 
root directory (the Student objects, for example). 

# Checking individual labs

Each lab is tagged. Run `git tag` to see a list. The highest increment of 
each tag for each lab is the ideal one to run. I.e., checkout v6.1 rather 
than v6.0. One may run `git checkout sometag` and compile and run the program 
as it existed at the time of turning it in. Future work may have overwritten 
or combined past work as time went on. Example gradeflow is below. Each tag 
has a readme in the respective lab with specific instructions.

    $ git clone http://github.com/aggroskater/cs3358-data-structures.git
    $ cd cs3358-data-structures
    $ git checkout v3.a.0
    $ cd lab3
    $ vim README.md
    $ g++ main.cpp queue.* ../student.* ../lab1/ll.* -g -o lab3
    $ ./lab3
    $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./lab3
