# LinkedList_Strings_Project_2015
Linked List Project

View this README in txt form for correct formatting (you can hit edit to see it in correct form).

In this project, you will use linked lists to represent
strings. You will implement functions that manipulate these linked lists to
transmute the strings they represent. In doing so, you will master the craft
of linked list manipulation!
By completing this assignment, you will also gain experience with file
I/O in C and processing command line arguments.

I. Input Files:
==============

1.1. Input File Format
The input file will begin with a single string that contains at least 1 character and no more than 1023
characters, and no spaces. Read in the string and convert it to a linked list. That will become your
working string, and you will manipulate it according to the remaining commands in the input file.
Each of the remaining lines in the file will correspond to one of the following string manipulation
commands:
Command             Description
-------             --------------
@ key str           key is a single character. str is a string. In your working string, replace all instances of key with str.
                    Note: key and str are guaranteed to contain alphanumeric characters only
                    (A-Z, a-z, and 0-9). str can range from 1 to 1023 characters (inclusively).
                    
- key               key is a single character. Delete all instances of key (if any) from your working string.

~                   Reverse the working string.

!                   Print the working string.


II. Sample Input/Output files:
=============================
Attached a few sample input and output files so you can check if the program is working.
