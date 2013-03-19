#Assignment

This lab was split into two parts. 

The first, part A, was to create a static stack (an array). It has a size 
of type integer with value specified by `STACK_SIZE` in `stack.h`.

The second, part B, was to both create a linked list of student objects, and 
to then push them onto a dynamic stack. In this implementation, the stack IS a 
linked list. One list will hold pointers to the Student objects. The other 
will serve as the stack and push/pop student pointers.

At present, we utilize copy constructors and assignment operators that provide 
non-const copies of Student objects whenever we need to pass objects between 
different structures. As it stands, the stack deletes its copy of the object, 
but the linked list retains its own. A stack really needs to delete its copy, 
but the linked list can have reason to keep its copy or discard, depending on 
use context. I plan to include support for this context sensitivity as 
detailed in ~/lab1/ll.cpp in the getStudent function.

#Compilation and Memory Checking

ALERT: Broken at the moment. Forgot to add stack\_ll files to repo from my
local machine. Can't fix until later tonight.

The code on branch master is lab2b. One may check out either branch lab2a or 
lab2b to test each assignment.

    $ g++ main.cpp stack_ll.* ../student.* ../lab1/ll.* -g -o lab2 
    $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./lab2 
