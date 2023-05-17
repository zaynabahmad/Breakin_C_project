#include "stdio.h"

#include "IO_interface.h"


char IO_PrintList(const char **Arg_ListPtr, int Arg_ListSize)
{
    /*Define Variable*/
    int Local_Iterator;

    /*Print a message to the user*/
    printf("\nChoices are: \n");

    /*Loop over the array of choices*/
    for(Local_Iterator = 0; Local_Iterator < Arg_ListSize; Local_Iterator++)
    {
        /*print the choices*/
        printf("Press %d :", (Local_Iterator + 1));
        printf((char *) Arg_ListPtr[Local_Iterator]);
        printf("\n");
    }
}
