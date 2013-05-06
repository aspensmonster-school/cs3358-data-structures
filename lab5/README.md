# About

This program implements quicksort for a vector of Student pointers, sorting 
by Student Id.

# Compilation and Memory Checking

    $ g++ -g main.cpp ../student.* -o lab5
    $ ./lab5
    $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./lab5
