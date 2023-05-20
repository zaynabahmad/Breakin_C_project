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
    /*Open the file*/
    Student *loc_sArr;
    int loc_nNum=0;
    loc_sArr=(Student*)malloc(1*sizeof(Student));
    loc_nNum=DFIL_nReadStudentRec(&loc_sArr);
    char **Local_MenusPtr = NULL;

    /*integer to carry the user choice*/
    int Local_ChoiceIndicator;

    /*integer to validate the input*/
    int Local_ChoiceIterator = 0;

    /*integer to carry the login state*/
    int Local_LoginState = 0;

    /*integer to still in the loop*/
    int Local_ListLoop;

    while(1)
    {
        /*Update the list loop flag*/
        Local_ListLoop = 1;

        /*Get the main list*/
        Menu_GetList(MAIN_LIST, &Local_MenusPtr);
        Input_ScanMenuChoice(Local_MenusPtr, MAIN_LIST_ITEMS, &Local_ChoiceIndicator);

        if(Local_ChoiceIndicator == 1)
        {
            Input_ScanLoginData(INPUT_ADMIN_TYPE, &Local_LoginState);

            if(Local_LoginState == 1)
            {
                Menu_GetList(ADMIN_LIST, &Local_MenusPtr);
                while(Local_ListLoop)
                {
                    Input_ScanMenuChoice(Local_MenusPtr, ADMIN_LIST_ITEMS, &Local_ChoiceIndicator);
                    switch(Local_ChoiceIndicator)
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
                        Local_ListLoop = 0;
                        break;
                    default:
                        printf("Wrong number\n");
                        break;
                    }
                }
            }
        }
        else if(Local_ChoiceIndicator == 2)
        {
            Input_ScanStudentLoginData(&loc_sArr, loc_nNum, &Local_LoginState);

            if(Local_LoginState == 1)
            {
                Menu_GetList(STUDENT_LIST, &Local_MenusPtr);
                while(Local_ListLoop)
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
                        Local_ListLoop = 0;
                        break;
                    default:
                        printf("Wrong number\n");
                        break;
                    }
                }
            }
        }
        else if(Local_ChoiceIndicator == 3)
        {
            break;
        }
        
    }

    /*Close the file and save the new data*/
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
