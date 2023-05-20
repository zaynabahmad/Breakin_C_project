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

void AADM_vAddStudent(Student *ptr_aStudents[],int *ptr_nNum)
{
    Student loc_sTemp;
    int loc_nBool=0;
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
    for(int i=0;i<*ptr_nNum;i++)
    {
        if((*ptr_aStudents)[i].id==loc_sTemp.id)
        {
            loc_nBool=1;
            break;
        }
    }
    while(loc_nBool)
    {
        printf("Id Already Exist\n");
        printf("Enter Student id or enter 1 to exit\n");
        scanf("%d",&loc_sTemp.id);
        if(loc_sTemp.id==1)
        {
            free(loc_sTemp.name);
            free(loc_sTemp.pass);
            return;
        }
        loc_nBool=0;
        for(int i=0;i<*ptr_nNum;i++)
        {
            if((*ptr_aStudents)[i].id==loc_sTemp.id)
            {
                loc_nBool=1;
                break;
            }
        }
    }
    printf("Enter student age\n");
    scanf("%d",&loc_sTemp.age);
    printf("Enter student grade\n");
    scanf("%f",&loc_sTemp.grade);
    while(loc_sTemp.grade>100||loc_sTemp.grade<0)
    {
        printf("Grade must be between 0 and 100\n");
        printf("Enter new Grade or Enter -1 for exit\n");
        scanf("%f",&loc_sTemp.grade);
        if(loc_sTemp.grade==-1)
        {
            free(loc_sTemp.name);
            free(loc_sTemp.pass);
            return;
        }
    }
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

void AADM_vRemoveStudent(Student *ptr_aStudents[],int *ptr_nNum)
{
    int loc_nId;
    int loc_nBool=0;
    printf("Enter student id\n");
    scanf("%d",&loc_nId);
    for(int i=0;i<*ptr_nNum;i++)
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
        scanf("%d",loc_nId);
        if(loc_nId==1)
        {
            return;
        }
        for(int i=0;i<*ptr_nNum;i++)
        {
            if((*ptr_aStudents)[i].id==loc_nId)
            {
                loc_nBool=1;
                break;
            }
        }
    }
    *ptr_nNum=DDMN_nDeleteStudent(ptr_aStudents,loc_nId,*ptr_nNum);
}

void AADM_vViewStudent(Student *ptr_aStudents[],int cpy_nNum)
{
    int loc_nId;
    int loc_nBool=0;
    printf("Enter student id\n");
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
        scanf("%d",loc_nId);
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
    DDMN_vViewStudentRecord(ptr_aStudents,loc_nId,loc_nId);
}

void AADM_vViewAllStudent(Student *ptr_aStudents[],int cpy_nNum)
{
    DDMN_vViewAllRecord(ptr_aStudents,cpy_nNum);
}

void AADM_vEditAdminPass()
{
    char*loc_pPass;
    DMMN_vAllocateSudentName(&loc_pPass);
    printf("Enter new admin pass\n");
    scanf("%s",loc_pPass);
    DFIL_vWriteAdminPass(loc_pPass);
}

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
