#Assignment

This lab was split into two parts. 

The first, part A, was to create a singly 
linked list populated with Student objects, and to display the list. 

The second, part B, was to extend this to a doubly linked list and add 
additional insertion, deletion, and sorting functions.

Ideally, we'd implement the list using templates. But for now, it is 
sufficient to use structs that hold the Object being manipulated.

#Compilation and Memory Checking

    $ g++ *.cpp -g -o lab1
    $ valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./lab1

#Implementation

This particular implementation tries to avoid using the stack as much as 
possible, instead opting to store both the linked list object itself, as well 
as the Student objects, in the heap. We create a linked list object on the
heap:

`ll* list = new ll;`

and we add student objects in the same manner:

    Student *temp = new Student(id,name,address,gpa);
    list->insertTail(temp);

However, this implementation might be improved by investigating the const 
operator, and seeing how the list behaves differently when the Student objects 
are const'd a la `insertTail(const Student* stu)`. I am deficient in my 
understanding of the subtleties of pass by reference and value in the context 
of the const keyword, and how it informs the behaviour of the program.
