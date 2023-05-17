#ifndef MENU_INTERFACE_
#define MENU_INTERFACE_

#define MAIN_LIST_ITEMS     2
#define ADMIN_LIST_ITEMS    6
#define STUDENT_LIST_ITEMS  3


typedef enum
{
	MAIN_LIST = 0,
    ADMIN_LIST,
    STDUENT_LIST
}Menu_Lists_ID_t;


/**
 * @brief A function to return a menu list to be printed to the user.
 * 
 * @param Arg_Menu          The list that needed to be printed.
 * @param Arg_ListSizePtr   Pointer to return the size of the needed list.
 * @param Arg_ListPtr       Pointer to return the list.
 * @return char             Error State.
 */
char Menu_GetLists(Menu_Lists_ID_t Arg_Menu, int *Arg_ListSizePtr, char ***Arg_ListPtr);

#endif