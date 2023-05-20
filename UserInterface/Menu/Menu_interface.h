#ifndef MENU_INTERFACE_
#define MENU_INTERFACE_

#define MAIN_LIST_ITEMS     3
#define ADMIN_LIST_ITEMS    7
#define STUDENT_LIST_ITEMS  4

#define MAIN_LIST_ARR       {"Admin Mode",\
                            "Student Mode",\
                            "Exit"}

#define ADMIN_LIST_ARR      {"To add student record",\
                            "To remove student record press",\
                            "To view student record",\
                            "To view all records",\
                            "To edit admin password",\
                            "To edit student grade",\
                            "To go to the main menu"}

#define STUDENT_LIST_ARR    {"To view your record",\
                            "To edit your password",\
                            "To edit your name",\
                            "To go to the main menu"}

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