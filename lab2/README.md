#Assignment

This lab was split into two parts. 

The first, part A, was to create a static stack (an array). It has a size 
of type integer with value specified by `STACK_SIZE` in `stack.h`.

The second, part B, was to both create a linked list of student objects, and 
to then push them onto a dynamic stack. In this implementation, the stack IS a 
linked list. One list will hold pointers to the Student objects. The other 
will serve as the stack and push/pop student pointers.

#Compilation and Memory Checking

The code on branch master is lab2b. One may check out either branch lab2a or 
lab2b to test each assignment.

    $ g++ *.cpp -g -o lab2
    $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./lab2
