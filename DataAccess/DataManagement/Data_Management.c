#include<stdio.h>
#include<stdlib.h>
#include"../Student_Struct.h"
#include"../MemoryManagement/Memory_Management.h"

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
int Data_Management_AddStudent(Student*Arg_Arr[],int Arg_n,Student Arg_NewStudent)
{
    Memory_Management_Allocate_Student_Memory(Arg_Arr,Arg_n);
    *(*(Arg_Arr)+Arg_n)=Arg_NewStudent;
    Arg_n++;
    return Arg_n;
}

/*
Use this function to edit a student's grade.
It takes a pointer to an array of students, the number of students, and the new grade as arguments.
*/
void Data_Management_EditStudentGrade(Student*Arg_Arr[],float Arg_Grade,int Arg_id,int Arg_n)
{
    for(int i=0;i<Arg_n;i++)
    {
        if((*Arg_Arr)[i].id==Arg_id)
        {
            (*Arg_Arr)[i].grade=Arg_Grade;
            return;
        }
    }
    printf("Data_Management_EditStudentGrade:Wrong id\n");
}

/*
Use this function to delete students.
It takes a pointer to an array of students, the number of students, and the ID of the student as arguments.
*/
int Data_Management_DeleteStudent(Student*Arg_Arr[],int Arg_id,int Arg_n)
{
    Student*Local_NewArr;
    Memory_Management_Delete_Student_Memory(&Local_NewArr,Arg_n);
    int i=0;
    for(int j=0;j<Arg_n;j++)
    {
        if((*Arg_Arr)[j].id==Arg_id)
        {
            j++;
        }
        if(i==Arg_n-1)
        {
            break;
        }
        Local_NewArr[i]=(*Arg_Arr)[j];
        i++;
    }
    free(*Arg_Arr);
    *Arg_Arr=Local_NewArr;
    Local_NewArr=NULL;
    return Arg_n-1;
}

/*
Use this function to print a student's grade.
It takes a pointer to an array of students, the number of students, and the ID of the student as arguments.
*/
void Data_Management_ViewStudentRecord(Student*Arg_Arr[],int Arg_id,int Arg_n)
{
    for(int i=0;i<Arg_n;i++)
    {
        if((*Arg_Arr)[i].id==Arg_id)
        {
            printf("%.2f\n",(*Arg_Arr)[i].grade);
            return;
        }
    }
    printf("Data_Management_ViewStudentRecord:Wrong id\n");
}

/*
Use this function to print all students grades.
It takes a pointer to an array of students, the number of students, and the ID of the student as arguments.
*/
void Data_Management_ViewAllRecord(Student*Arg_Arr[],int Arg_n)
{
    for(int i=0;i<Arg_n;i++)
    {
        printf("%.2f\n",(*Arg_Arr)[i].grade);
    }
}
