#include "stdio.h"
#include "../../Error_Handling.h"
#include "../../DataAccess/student_struct.h"
#include "Input_interface.h"
#include "Output_interface.h"
#include "../../Application/Authentication/Authentication_interface.h"

char Input_ScanMenuChoice(char **Arg_ChoicesArr, int Arg_ListSize, int *Arg_ChoiceIndicator)
{
    char Local_ErrorState = OK;
    int Local_ChoiceIterator;
    int Local_ChoiceIndicator;

    if(Arg_ChoicesArr != NULL)
    {
        Local_ChoiceIterator = 3;
        while(Local_ChoiceIterator != 0)
        {
            /*Increase the iterator*/
            Local_ChoiceIterator--;

            /*Print the main list*/
            Output_PrintList(Arg_ChoicesArr, Arg_ListSize);

            /*Scan the choice*/
            scanf("%d", &Local_ChoiceIndicator);

            /*Validate the number*/
            if((Local_ChoiceIndicator <= Arg_ListSize) && (Local_ChoiceIndicator > 0))
            {
                *Arg_ChoiceIndicator = Local_ChoiceIndicator;
                break;
            }
            else
            {
                Output_PrintWrongInput(Local_ChoiceIterator);
            }
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}

char Input_ScanLoginData(char Arg_UserType, int *Arg_LoginState)
{
    char Local_ErrorState = OK;

    char Local_AdminUsername[50] = {0};
    char Local_Password[50] = {0};
    int Local_LoginState = 0;
    int Local_StudentID = 0;

    int Local_LoginIterator = 3;

    if(Arg_LoginState != NULL)
    {
        while(Local_LoginIterator != 0)
        {
            /*Increase the iterator*/
            Local_LoginIterator--;

            switch(Arg_UserType)
            {
            case INPUT_ADMIN_TYPE:
                printf("Login:\n");
                printf("Admin Password: ");
                scanf("%49s", Local_Password);

                /*Authonticate Admin Password*/
                Authent_ValidateAdminData(Local_Password, &Local_LoginState);

                *Arg_LoginState = Local_LoginState;
                break;

            case INPUT_STUDENT_TYPE:
                printf("\nLogin:\n");
                printf("ID: ");
                scanf("%d", &Local_StudentID);
                printf("Password: ");
                scanf("%d", &Local_Password);

                /*Authonticate Student Username and Password*/
                *Arg_LoginState = 1;
                break;
            }


            /*Validate the number*/
            if(Local_LoginState == 1)
            {
                break;
            }
            else
            {
                Output_PrintWrongInput(Local_LoginIterator);
            }
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


char Input_ScanStudentLoginData(Student *Arg_StudentArr[], int Arg_StudentsNum, int *Arg_LoginState)
{
    char Local_ErrorState = OK;

    char Local_AdminUsername[50] = {0};
    char Local_Password[50] = {0};
    int Local_LoginState = 0;
    int Local_StudentID = 0;

    int Local_LoginIterator = 3;

    if(Arg_LoginState != NULL)
    {
        while(Local_LoginIterator != 0)
        {
            /*Increase the iterator*/
            Local_LoginIterator--;

                printf("\nLogin:\n");
                printf("ID: ");
                scanf("%d", &Local_StudentID);
                printf("Password: ");
                scanf("%49s", Local_Password);

                /*Authonticate Student Username and Password*/
                Local_LoginState = Authent_ValidateStudentData(Arg_StudentArr, Local_StudentID, Local_Password, Arg_StudentsNum);
                *Arg_LoginState = Local_LoginState;

            /*Validate the number*/
            if(Local_LoginState == 1)
            {
                break;
            }
            else
            {
                Output_PrintWrongInput(Local_LoginIterator);
            }
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}
