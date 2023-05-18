#include<stdio.h>
#include<stdlib.h>
#include"../student_struct.h"
#include"../MemoryManagement/memory_management.h"
/**
 * @file Data_Management.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with student data in a dynamic array.
 * @version 0.1
 * @date 2023-05-15
 */

 /**
 *brief :Use this function to add students.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 *@param cpy_sNewStudent:New Student
 *@return int:new number of students
 */
int DDMN_nAddStudent(Student*ptr_aStudent[],int cpy_nNum,Student cpy_sNewStudent)
{
    DMMN_vAllocateStudentMemory(ptr_aStudent,cpy_nNum);
    *(*(ptr_aStudent)+cpy_nNum)=cpy_sNewStudent;
    cpy_nNum++;
    return cpy_nNum;
}

 /**
 *brief :Use this function to edit a student's grade.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 *@param cpy_nId:ID for a wanted student
 *@param cpy_fGrade:New grade
 */
void DDMN_vEditStudentGrade(Student*ptr_aStudent[],float cpy_fGrade,int cpy_nId,int cpy_nNum)
{
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudent)[i].id==cpy_nId)
        {
            (*ptr_aStudent)[i].grade=cpy_fGrade;
            return;
        }
    }
    printf("Data_Management_EditStudentGrade:Wrong id\n");
}

 /**
 *brief :Use this function to delete students.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 *@param cpy_nId:ID for a wanted student
 *@return int:new number of students
 */
int DDMN_nDeleteStudent(Student*ptr_aStudent[],int cpy_nId,int cpy_nNum)
{
    Student*loc_ptr_sNewArr;
    DMMN_vDeleteStudentMemory(&loc_ptr_sNewArr,cpy_nNum);
    int i=0;
    for(int j=0;j<cpy_nNum;j++)
    {
        if((*ptr_aStudent)[j].id==cpy_nId)
        {
            j++;
        }
        if(i==cpy_nNum-1)
        {
            break;
        }
        loc_ptr_sNewArr[i]=(*ptr_aStudent)[j];
        i++;
    }
    free(*ptr_aStudent);
    *ptr_aStudent=loc_ptr_sNewArr;
    loc_ptr_sNewArr=NULL;
    return cpy_nNum-1;
}

 /**
 *brief :Use this function to print a student's grade.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 *@param cpy_nId:ID for a wanted student
 */
void DDMN_vViewStudentRecord(Student*ptr_aStudent[],int cpy_nId,int cpy_nNum)
{
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudent)[i].id==cpy_nId)
        {
            printf("%.2f\n",(*ptr_aStudent)[i].grade);
            return;
        }
    }
    printf("Data_Management_ViewStudentRecord:Wrong id\n");
}

 /**
 *brief :Use this function to print a student's grade.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 */
void DDMN_vViewAllRecord(Student*ptr_aStudent[],int cpy_nNum)
{
    for(int i=0;i<cpy_nNum;i++)
    {
        printf("%.2f\n",(*ptr_aStudent)[i].grade);
    }
}
