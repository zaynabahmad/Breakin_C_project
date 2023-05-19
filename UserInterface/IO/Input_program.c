#include "stdio.h"

#include "../../Error_Handling.h"

#include "Input_interface.h"
#include "Output_interface.h"


char Input_ScanNumber(void)
{
    /*Define Variables*/
    int Local_ScannedNumber;

    /*Scan the number*/
    scanf("%d", &Local_ScannedNumber);

    /*Return the number*/
    return Local_ScannedNumber;
}

char Input_ScanMenuChoice(char **Arg_ChoicesArr, int Arg_ListSize, int *Arg_ChoiceIndicator)
{
    char Local_ErrorState = OK;
    char Local_ChoiceIterator;
    
    if(Arg_ChoicesArr != NULL)
    {
        Local_ChoiceIterator = 3;
        while(Local_ChoiceIterator != 0)
        {
            /*Increase the iterator*/
            Local_ChoiceIterator--;

            /*Print the main list*/
            Output_PrintList(Arg_ChoicesArr, Arg_ListSize);

            /*Scan the mode*/
            *Arg_ChoiceIndicator = Input_ScanNumber();

            /*Validate the number*/
            if((*Arg_ChoiceIndicator <= Arg_ListSize) && (*Arg_ChoiceIndicator > 0))
            {
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

char Input_ScanLoginData(char Arg_UserType, char *Arg_LoginState)
{
    char Local_ErrorState = OK;

    char Local_AdminUsername[50] = {0};
    int Local_Password = 0;
    char Local_LoginState = 0;
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
                printf("Username: ");
                scanf("%49s", Local_AdminUsername);
                printf("Password: ");
                scanf("%d", &Local_Password);

                /*Authonticate Admin Username and Password*/
                *Arg_LoginState = 0;
                break;

            case INPUT_STUDENT_TYPE: 
                printf("\nLogin:\n");
                printf("ID: ");
                scanf("%d", &Local_StudentID);
                printf("Password: ");
                scanf("%d", &Local_Password);

                /*Authonticate Student Username and Password*/
                *Arg_LoginState = 0;
                break;
            }


            /*Validate the number*/
            if(*Arg_LoginState == 1)
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
