#include<stdio.h>
#include<stdlib.h>
#include"../../DataAccess/student_struct.h"
#include"../../DataAccess/MemoryManagement/memory_management.h"
#include"../../DataAccess/DataManagement/data_management.h"

/**
 * @file student.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with student mode.
 * @version 0.1
 * @date 2023-05-18
 */

  /**
 *brief :Use this function to print student record.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 */
void ASTU_vViewRecord(Student *ptr_aStudents[],int cpy_nNum)
{
    int loc_nId=0;
    int loc_nBool=0;
    printf("Enter Your ID\n");
    scanf("%d",&loc_nId);
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_nId)
        {
            loc_nBool=1;
            break;
        }
    }
    while(loc_nBool==0)
    {
        printf("ID dosen't exist\n");
        printf("Enter id or Enter 1 to exit\n");
        scanf("%d",&loc_nId);
        if(loc_nId==1)
        {
            return;
        }
        for(int i=0;i<cpy_nNum;i++)
        {
            if((*ptr_aStudents)[i].id==loc_nId)
            {
                loc_nBool=1;
                break;
            }
        }
    }
    DDMN_vViewStudentRecord(ptr_aStudents,loc_nId,cpy_nNum);
}

/**
 *brief :Use this function to edit student name.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 */
void ASTU_vEditPass(Student *ptr_aStudents[],int cpy_nNum)
{
    int loc_nId=0;
    int loc_nBool=0;
    printf("Enter Your ID\n");
    scanf("%d",&loc_nId);
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_nId)
        {
            loc_nBool=1;
            break;
        }
    }
    while(loc_nBool==0)
    {
        printf("ID dosen't exist\n");
        printf("Enter id or Enter 1 to exit\n");
        scanf("%d",&loc_nId);
        if(loc_nId==1)
        {
            return;
        }
        for(int i=0;i<cpy_nNum;i++)
        {
            if((*ptr_aStudents)[i].id==loc_nId)
            {
                loc_nBool=1;
                break;
            }
        }
    }
    char*loc_pPass;
    char*loc_pTemp;
    DMMN_vAllocateSudentName(&loc_pPass);
    printf("Enter your new pass\n");
    scanf("%s",loc_pPass);
    DMMN_vResizeSudentName(&loc_pPass);
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_nId)
        {
            loc_pTemp=(*ptr_aStudents)[i].pass;
            (*ptr_aStudents)[i].pass=loc_pPass;
            free(loc_pTemp);
            return;
        }
    }
    printf("Wrong Id");
}

/**
 *brief :Use this function to edit student name.
 *@param ptr_aStudent:pointer to Students array
 *@param cpy_nNum:Number of students in array
 */
void ASTU_vEditName(Student *ptr_aStudents[],int cpy_nNum)
{
    int loc_nId=0;
    printf("Enter Your ID\n");
    scanf("%d",&loc_nId);
    int loc_nBool=0;
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_nId)
        {
            loc_nBool=1;
            break;
        }
    }
    while(loc_nBool==0)
    {
        printf("ID dosen't exist\n");
        printf("Enter id or Enter 1 to exit\n");
        scanf("%d",&loc_nId);
        if(loc_nId==1)
        {
            return;
        }
        for(int i=0;i<cpy_nNum;i++)
        {
            if((*ptr_aStudents)[i].id==loc_nId)
            {
                loc_nBool=1;
                break;
            }
        }
    }
    //Authentication
    char*loc_pTemp;
    char*loc_pName;
    DMMN_vAllocateSudentName(&loc_pName);
    printf("Enter your new name\n");
    scanf("%s",loc_pName);
    DMMN_vResizeSudentName(&loc_pName);
    for(int i=0;i<cpy_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_nId)
        {
            loc_pTemp=(*ptr_aStudents)[i].name;
            (*ptr_aStudents)[i].name=loc_pName;
            free(loc_pTemp);
            return;
        }
    }
    printf("Wrong Id");
}
