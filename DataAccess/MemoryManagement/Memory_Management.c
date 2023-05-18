#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../Student_struct.h"
/**
 * @file Memory_Management.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with memory in Heab.
 * @version 0.1
 * @date 2023-05-15
 */

/**
 *brief :Use this function to initially allocate memory for student names or pass
 *@param ptr_aName:pointer to a character pointer
 */
void DMMN_vAllocateSudentName(char **ptr_aName)
{
    *ptr_aName=(char*)malloc(50*sizeof(char));
}

/**
 *brief :Use this function to reduce memory allocated for student names or pass
 *@param ptr_aName:pointer to a character pointer
 */
void DMMN_vResizeSudentName(char **ptr_aName)
{
    *ptr_aName=(char*)realloc(*Arg_P,strlen(*Arg_P)+1);
}

/**
 *brief :Use this function to increase the size of the dynamic array by one.
 *@param ptr_aStudents:pointer to Students array
 *@param cpy_nNum:number of students
 */
void DMMN_vAllocateStudentMemory(Student *ptr_aStudents[],int cpy_nNum)
{
    *ptr_aStudents=(Student*)realloc(*ptr_aStudents,(cpy_nNum+1)*sizeof(Student));
}

/**
 *brief :Use this function to allocate memory for a new array whose size is smaller than the student array by one.
 *@param ptr_aStudents:pointer to Students array
 *@param cpy_nNum:number of students
 */
void DMMN_vDeleteStudentMemory(Student**ptr_aStudents,int cpy_nNum)
{
    *ptr_aStudents=(Student*)malloc((cpy_nNum-1)*sizeof(Student));
}
