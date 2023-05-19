#include "../../Error_Handling.h"

#include "Menu_interface.h"

char *Menu_MainList[MAIN_LIST_ITEMS] = MAIN_LIST_ARR;

char *Menu_AdminList[ADMIN_LIST_ITEMS] = ADMIN_LIST_ARR;

char *Menu_StudentList[STUDENT_LIST_ITEMS] = STUDENT_LIST_ARR;


char Menu_GetList(Menu_Lists_ID_t Arg_Menu, char ***Arg_ListPtr)
{
    /*Define Error State Variable*/
    char Local_ErrorState = OK;

    /*Validate Pointer*/
    if(Arg_ListPtr != NULL)             //Pointer is valid.
    {
        /*Return the menu needed*/
        switch(Arg_Menu)
        {
            case MAIN_LIST:     *Arg_ListPtr = (char **) Menu_MainList;     break;
            case ADMIN_LIST:    *Arg_ListPtr = (char **) Menu_AdminList;    break;
            case STUDENT_LIST:  *Arg_ListPtr = (char **) Menu_StudentList;  break;
            default:            Local_ErrorState = NOK;                     break;
        }
    }
    else                                //Pointer is invalid.
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    /*Return Error State*/
    return Local_ErrorState;
}