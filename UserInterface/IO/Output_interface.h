#ifndef OUTPUT_INTERFACE_
#define OUTPUT_INTERFACE_

/**
 * @brief A function to print a list of choices.
 * 
 * @param Arg_ListPtr   Pointer to array of strings which are the choices.
 * @param Arg_ListSize  Number of choices in the array.
 *
 * @return char         Error State.
 */
char Output_PrintList(char **Arg_ListPtr, int Arg_ListSize);

void Output_PrintWrongInput(char Arg_RemainAttempts);

void Output_ClrScr();
#endif