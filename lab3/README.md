#Assignment

This lab was to create a dynamic queue data structure for part A. The second 
part, B, was extra credit. I don't remember what it was at this point. 

#Compilation and Memory Checking

The code on branch master is lab3. One may check out either branch lab3 or 
clone master and do the following.

    $ g++ main.cpp queue.* ../student.* ../lab1/ll.* -g -o lab3 
    $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./lab3
