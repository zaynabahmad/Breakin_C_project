#include "UserInterface/IO/Output_interface.h"
#include "UserInterface/IO/Input_interface.h"
#include "UserInterface/Menu/Menu_interface.h"

#include "Student_Struct.h"

#include "Error_Handling.h"

#include "stdio.h"

int main()
{
    /*Pointer to assign to any menu, menu is an array of strings*/
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
            Input_ScanMenuChoice(Local_MenusPtr, ADMIN_LIST_ITEMS, &Local_ChoiceIndicator);
            switch(Local_ChoiceIndicator)
            {
                case 1:
                case 2:
                break;
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
        }
        
        switch(Local_ChoiceIndicator)
        {
            case 1:
            case 2:
            break;
        }
    }
    
    printf("Last line");

    return 0;
}