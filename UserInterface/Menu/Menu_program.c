#include "../../Error_Handling.h"

#include "Menu_interface.h"

char *Menu_MainList[MAIN_LIST_ITEMS] = {
    "Admin Mode",
    "Student Mode"
};

char *Menu_AdminList[ADMIN_LIST_ITEMS] = {
    "To add student record",
    "To remove student record press",
    "To view student record",
    "To view all records",
    "To edit admin password",
    "To edit student grade"
};

char *Menu_StudentList[STUDENT_LIST_ITEMS] = {
    "To view your record",
    "To edit your password",
    "To edit your name"
};


char Menu_GetLists(Menu_Lists_ID_t Arg_Menu, int *Arg_ListSizePtr, char ***Arg_ListPtr)
{
    /*Define Error State Variable*/
    char Local_ErrorState = OK;

    /*Validate Pointers*/
    if((Arg_ListPtr != NULL)&& (Arg_ListSizePtr != NULL))
    /*Pointers are valid*/
    {
        /*Return the menu needed*/
        switch(Arg_Menu)
        {
            case MAIN_LIST: *Arg_ListPtr = (char **) Menu_MainList;    *Arg_ListSizePtr = MAIN_LIST_ITEMS;   break;
            case ADMIN_LIST: *Arg_ListPtr = (char **) Menu_AdminList;    *Arg_ListSizePtr = ADMIN_LIST_ITEMS;   break;
            case STDUENT_LIST: *Arg_ListPtr = (char **) Menu_StudentList;  *Arg_ListSizePtr = STUDENT_LIST_ITEMS;  break;
            default: Local_ErrorState = NOK;    break;
        }
    }
    else
    /*There is an invalid pointer*/
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    /*Return Error State*/
    return Local_ErrorState;
}