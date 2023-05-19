#ifndef MENU_INTERFACE_
#define MENU_INTERFACE_

#define MAIN_LIST_ITEMS     2
#define ADMIN_LIST_ITEMS    6
#define STUDENT_LIST_ITEMS  3

#define MAIN_LIST_ARR       {"Admin Mode",\
                            "Student Mode"}

#define ADMIN_LIST_ARR      {"To add student record",\
                            "To remove student record press",\
                            "To view student record",\
                            "To view all records",\
                            "To edit admin password",\
                            "To edit student grade"}

#define STUDENT_LIST_ARR    {"To view your record",\
                            "To edit your password",\
                            "To edit your name"}

typedef enum
{
	MAIN_LIST = 0,
    ADMIN_LIST,
    STUDENT_LIST
}Menu_Lists_ID_t;


/**
 * @brief A function to return a menu list to be printed to the user.
 * 
 * @param Arg_Menu          The list that needed to be printed.
 * @param Arg_ListPtr       Pointer to return the list.
 * 
 * @return char             Error State.
 */
char Menu_GetList(Menu_Lists_ID_t Arg_Menu, char ***Arg_ListPtr);

#endif