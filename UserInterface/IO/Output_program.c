#include "stdio.h"
#include "../../Error_Handling.h"

#include "Output_interface.h"


char Output_PrintList(const char **Arg_ListPtr, int Arg_ListSize)
{
    /*Define Variables*/
    char Local_ErrorState = OK;
    int Local_Iterator;

    /*Validate the pointer*/
    if(Arg_ListPtr != NULL)         //Pointer is valid
    {
        /*Print a message to the user*/
        printf("\nChoices are: \n");

        /*Loop over the array of choices*/
        for(Local_Iterator = 0; Local_Iterator < Arg_ListSize; Local_Iterator++)
        {
            /*Print choices*/
            printf("Press %d :", (Local_Iterator + 1));
            printf((char *) Arg_ListPtr[Local_Iterator]);
            printf("\n");
        }

        /*Print a message to the user*/
        printf("\nYour Reply: ");
    }
    else                            //Pointer in invalid
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    /*Return Error State*/
    return Local_ErrorState;
}

void Output_PrintWrongInput(char Arg_RemainAttempts)
{
    printf("\nWrong Input!\n");
    if(Arg_RemainAttempts != 0)
    {
        printf("%d Left Attempts.\n", Arg_RemainAttempts);
    }
    else
    {
        printf("No More Attempts!\n");
    }
}