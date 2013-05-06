# Sorting the input

    $ awk 'NR % 2 == 1' input.txt | sort -t$';' -k1 -n > input-sorted.txt

I then added the grades in manually.

# Compilation and Memory Checking

    $ g++ -g main.cpp ../student.* -o lab4
    $ ./lab4
    $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./lab4

