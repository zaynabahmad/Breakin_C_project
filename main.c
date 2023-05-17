#include "UserInterface/IO/IO_interface.h"
#include "UserInterface/Menu/Menu_interface.h"
#include "Error_Handling.h"

#include "stdio.h"

int main()
{
    char **Local_MainPtr = NULL;
    int Local_MainSize;

    Menu_GetLists(ADMIN_LIST, &Local_MainSize, &Local_MainPtr);

    IO_PrintList((const char **) Local_MainPtr, Local_MainSize);
    return 0;
}