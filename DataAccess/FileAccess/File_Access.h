#ifndef FILE_ACCESS
#define FILE_ACCESS
#include"../Student_Struct.h"

/*
*File_Access.h
*Moamen eltony
*This file contains functions that deal with data in DataBase.
*Version 1.0
*2023-05-15
*/


/*
Use this function to delete records from the database.
*/
void FileAccess_voidDeleteAllRec(void);

/*
Use this function to add students to the database. 
It takes student structure as argument.
*/
void FileAccess_voidWriteStudentRec(Student Arg_studentRecord);

/*
Use this function to read all sensitive data from the database.
It takes a pointer to an array of students as an argument.
return number of the student
*/
int FileAccess_voidReadStudentRec(Student**Arg_Arr);

/*
Use this function to read admin passwords from the database. 
It returns the admin password as a string.
*/
char* FileAccess_voidReadAdminPass(void);

/*
Use this function to update the admin record.
It takes a char pointer as an argument.
*/
void FileAccess_voidWriteAdminPass(char *Arg_AdminPass);
#endif