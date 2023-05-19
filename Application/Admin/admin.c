#include<stdio.h>
#include<stdlib.h>
#include"../../DataAccess/student_struct.h"
#include"../../DataAccess/DataManagement/data_management.h"
#include"../../DataAccess/FileAccess/file_access.h"
#include"../../DataAccess/MemoryManagement/memory_management.h"

/**
 * @file admin.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with student mode.
 * @version 0.1
 * @date 2023-05-18
 */

/**
 *brief :Use this function to add student to dynamic array.
 *@param ptr_aStudent:pointer to Students array
 *@param ptr_nNum:Number of students in array
 */
void AADM_vAddStudent(Student *ptr_aStudents[],int *ptr_nNum)
{
    Student loc_sTemp;
    int loc_nGender;
    char*loc_pName;
    char*loc_pPass;
    DMMN_vAllocateSudentName(&loc_pName);
    DMMN_vAllocateSudentName(&loc_pPass);
    printf("Enter student name\n");
    scanf("%s",loc_pName);
    DMMN_vResizeSudentName(&loc_pName);
    loc_sTemp.name=loc_pName;
    loc_pName=NULL;
    printf("Enter student pass\n");
    scanf("%s",loc_pPass);
    DMMN_vResizeSudentName(&loc_pPass);
    loc_sTemp.pass=loc_pPass;
    loc_pPass=NULL;
    printf("Enter student id\n");
    scanf("%d",&loc_sTemp.id);
    printf("Enter student age\n");
    scanf("%d",&loc_sTemp.age);
    printf("Enter student grade\n");
    scanf("%f",&loc_sTemp.grade);
    while(1)
    {
        printf("Enter 1 for male\nEnter 2 for Female\n");
        scanf("%d",&loc_nGender);
        if(loc_nGender==1)
        {
             loc_sTemp.gender='m';
             break;
        }
        else if(loc_nGender==2)
        {
            loc_sTemp.gender='f';
            break;
        }
        printf("Application;Wrong number\n");
    }
    for(int i=0;i<*ptr_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_sTemp.id)
        {
            printf("Applicaton:Id Already exist\n");
            free(loc_sTemp.name);
            free(loc_sTemp.pass);
            loc_sTemp.name=NULL;
            loc_sTemp.pass=NULL;
            return;
        }
    }
    *ptr_nNum=DDMN_nAddStudent(ptr_aStudents,*ptr_nNum,loc_sTemp);
}

/**
 *brief :Use this function to remove student from dynamic array.
 *@param ptr_aStudent:pointer to Students array
 *@param ptr_nNum:Number of students in array
 */
void AADM_vRemoveStudent(Student *ptr_aStudents[],int *ptr_nNum)
{
    int loc_nId;
    printf("Enter student id\n");
    scanf("%d",&loc_nId);
    *ptr_nNum=DDMN_nDeleteStudent(ptr_aStudents,loc_nId,*ptr_nNum);
}

/**
 *brief :Use this function to view student record.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 */
void AADM_vViewStudent(Student *ptr_aStudents[],int cpy_nNum)
{
    int loc_nId;
    printf("Enter student id\n");
    scanf("%d",&loc_nId);
    DDMN_vViewStudentRecord(ptr_aStudents,loc_nId,loc_nId);
}

/**
 *brief :Use this function to view all students record.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 */
void AADM_vViewAllStudent(Student *ptr_aStudents[],int cpy_nNum)
{
    DDMN_vViewAllRecord(ptr_aStudents,cpy_nNum);
}

/**
 *brief :Use this function to Edit Admin pass.
 */
void AADM_vEditAdminPass()
{
    char*loc_pPass;
    DMMN_vAllocateSudentName(&loc_pPass);
    printf("Enter new admin pass\n");
    scanf("%s",loc_pPass);
    DFIL_vWriteAdminPass(loc_pPass);
}

/**
 *brief :Use this function to edit student grade.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 */
void AADM_vEditStudentGrade(Student *ptr_aStudents[],int cpy_nNum)
{
    int loc_nId;
    printf("Enter student id\n");
    scanf("%d",&loc_nId);
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_nId)
        {
             float loc_fGrade;
             printf("Enter new grade\n");
             scanf("%f",&loc_fGrade);
             DDMN_vEditStudentGrade(ptr_aStudents,loc_fGrade,loc_nId,cpy_nNum);
             return;
        }
    }
    printf("Application:Wrong id\n");
}
