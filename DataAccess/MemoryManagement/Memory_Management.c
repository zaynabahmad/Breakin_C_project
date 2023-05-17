#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../Student_struct.h"

/*
*Memory_Management.h
*Moamen eltony
*This file contains functions that deal with memory in Heab.
*Version 1.0
*2023-05-15
*/

/*
Use this function to initially allocate memory for student names or pass
It takes a pointer to a character pointer as an argument.
*/
void Memory_Management_Allocate_SudentName(char **Arg_P)
{
    *Arg_P=(char*)malloc(50*sizeof(char));
}

/*
Use this function to reduce memory allocated for student names or pass
It takes a pointer to a character pointer as an argument.
*/
void Memory_Management_Resize_SudentName(char **Arg_P)
{
    *Arg_P=(char*)realloc(*Arg_P,strlen(*Arg_P)+1);
}

/*
Use this function to increase the size of the dynamic array by one.
It takes a pointer to a array of Structs and number of students as an argument.
*/
void Memory_Management_Allocate_Student_Memory(Student *Arg_Arr[],int  Arg_n)
{
    *Arg_Arr=(Student*)realloc(*Arg_Arr,(Arg_n+1)*sizeof(Student));
}

/*
Use this function to allocate memory for a new array whose size is smaller than the student array by one.
It takes a pointer to an array of structures and the number of students as an argument.
*/
void Memory_Management_Delete_Student_Memory(Student**Arg_P,int Arg_n)
{
    *Arg_P=(Student*)malloc((Arg_n-1)*sizeof(Student));
}
