#ifndef Memory_Management
#define Memory_Management
#include "../Student_struct.h"
/*
*Memory_Management.h
*Moamen eltony
*This file contains functions that deal with memory in Heab.
*Version 1.0
*2023-05-15
*/

/*
Use this function to allocate memory for the student name or pass.
It takes a pointer to a character pointer as an argument.
*/
void Memory_Management_Allocate_SudentName(char **Arg_P);

/*
Use this function to reallocate memory for student names or pass.
It takes a pointer to a character pointer as an argument.
*/
void Memory_Management_Resize_SudentName(char **Arg_P);

/*
Use this function to increase the amount of memory allocated to students by one.
It takes a ponter to use the array of students and the number of students as arguments.
*/
void Memory_Management_Allocate_Student_Memory(Student *Arg_Arr[],int  Arg_n);

/*
Use this function to allot memory to a new array of students after deleting one student.
It takes a philosopher to use the array of students and the number of students as arguments. 
*/
void Memory_Management_Delete_Student_Memory(Student**Arg_P,int Arg_n);

#endif
