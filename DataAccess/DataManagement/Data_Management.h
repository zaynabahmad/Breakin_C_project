#ifndef Data_Management
#define Data_Management
#include"../Student_Struct.h"

/*
*Data_Management.h
*Moamen eltony
*This file contains functions that deal with student data in a dynamic array.
*Version 1.0
*2023-05-15
*/

/*
Use this function to add students.
It takes a pointer to an array of students, the number of students, and the new student as arguments.
*/
int Data_Management_AddStudent(Student*Arg_Arr[],int Arg_n,Student Arg_NewStudent);

/*
Use this function to edit a student's grade.
It takes a pointer to an array of students, the number of students, and the new grade as arguments.
*/
void Data_Management_EditStudentGrade(Student*Arg_Arr[],float Arg_Grade,int Arg_id,int Arg_n);

/*
Use this function to delete students.
It takes a pointer to an array of students, the number of students, and the ID of the student as arguments.
*/
int Data_Management_DeleteStudent(Student*Arg_Arr[],int Arg_id,int Arg_n);

/*
Use this function to print a student's grade.
It takes a pointer to an array of students, the number of students, and the ID of the student as arguments.
*/
void Data_Management_ViewStudentRecord(Student*Arg_Arr[],int Arg_id,int Arg_n);

/*
Use this function to print all students grades.
It takes a pointer to an array of students, the number of students, and the ID of the student as arguments.
*/
void Data_Management_ViewAllRecord(Student*Arg_Arr[],int Arg_n);
#endif
