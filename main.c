#include<stdio.h>
#include<stdlib.h>
#include"DataAccess/FileAccess/File_Access.h"
#include"DataAccess/MemoryManagement/memory_management.h"
#include"DataAccess/DataManagement/Data_Management.h"
#include"DataAccess/Student_Struct.h"
#include"Application/Student/student.h"
#include"Application/Admin/admin.h"
#include"Application/Authentication/Authentication_interface.h"
#include"UserInterface/IO/Input_interface.h"
#include"UserInterface/IO/Output_interface.h"
#include"UserInterface/Menu/Menu_interface.h"
#include"Application/Authentication/Authentication_interface.h"
int main()
{
    Student *loc_sArr;
    int loc_nNum=0;
    loc_sArr=(Student*)malloc(1*sizeof(Student));
    loc_nNum=DFIL_nReadStudentRec(&loc_sArr);
    char **Local_MenusPtr = NULL;

    /*Character to carry the user choice*/
    char Local_ChoiceIndicator;

    /*Char to validate the input*/
    char Local_ChoiceIterator = 0;

    /*Char to carry the login state*/
    char Local_LoginState = 0;

    /*Get the main list*/
    Menu_GetList(MAIN_LIST, &Local_MenusPtr);
    Input_ScanMenuChoice(Local_MenusPtr, MAIN_LIST_ITEMS, &Local_ChoiceIndicator);
    if(Local_ChoiceIndicator == 1)
    {
        Input_ScanLoginData(INPUT_ADMIN_TYPE, &Local_LoginState);

        if(Local_LoginState == 1)
        {
            Menu_GetList(ADMIN_LIST, &Local_MenusPtr);
            int loc_nAdminBool=1;
            while(loc_nAdminBool)
            {
            printf("1 To add student record\n");
            printf( "2 To remove student record press\n");
            printf("3 To view student record\n");
            printf("4 To view all records\n");
            printf("5 To edit admin password\n");
            printf("6 To edit student grade\n");
            int n=0;
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                AADM_vAddStudent(&loc_sArr,&loc_nNum);
                break;
            case 2:
                AADM_vRemoveStudent(&loc_sArr,&loc_nNum);
                break;
            case 3:
                AADM_vViewStudent(&loc_sArr,loc_nNum);
                break;
            case 4:
                AADM_vViewAllStudent(&loc_sArr,loc_nNum);
                break;
            case 5:
                AADM_vEditAdminPass();
                break;
            case 6:
                AADM_vEditStudentGrade(&loc_sArr,loc_nNum);
                break;
            case 7:
                loc_nAdminBool=0;
                break;
            default:
                printf("Wrong Number\n");
                break;
            }
            }
        }
    }
    else if(Local_ChoiceIndicator == 2)
    {
        Input_ScanLoginData(INPUT_STUDENT_TYPE, &Local_LoginState);

        if(Local_LoginState == 1)
        {
            Menu_GetList(STUDENT_LIST, &Local_MenusPtr);
            Input_ScanMenuChoice(Local_MenusPtr, STUDENT_LIST_ITEMS, &Local_ChoiceIndicator);
            int loc_nStudentBool=1;
            while(loc_nStudentBool)
            {
            Input_ScanMenuChoice(Local_MenusPtr, STUDENT_LIST_ITEMS, &Local_ChoiceIndicator);
            switch(Local_ChoiceIndicator)
            {
            case 1:
                ASTU_vViewRecord(&loc_sArr,loc_nNum);
                break;
            case 2:
                ASTU_vEditPass(&loc_sArr,loc_nNum);
                break;
            case 3:
                ASTU_vEditName(&loc_sArr,loc_nNum);
                break;
            case 4:
                loc_nStudentBool=0;
                break;
            default:
                printf("Wrong number\n");
                break;

            }
            }
        }
    }
    DFIL_vDeleteAllRec();
    for(int i=0;i<loc_nNum;i++)
    {
        DFIL_vWriteStudentRec(loc_sArr[i]);
        free(loc_sArr[i].name);
        free(loc_sArr[i].pass);
        loc_sArr[i].name=NULL;
        loc_sArr[i].pass=NULL;
    }
    return 0;
}
