#include "../../DataAccess/student_struct.h"
#include "Authentication_interface.h"
#include "../../DataAccess/student_struct.h"
#include "../../DataAccess/MemoryManagement/memory_management.h"
#include"../../DataAccess/FileAccess/file_access.h"
#include "string.h"

void Authent_ValidateAdminData(char *Arg_Password, int *Arg_LoginState)
{
    *Arg_LoginState = 1;

    char *Local_Password = DFIL_pReadAdminPass();
    char Local_Temp = 10;

    int Local_PasswordSize = 0;
    int Local_InputedPasswordSize = 0;
    int Local_LoopIterator;
    int Local_State = 1;

    /*Find the length of the password*/
    while(1)
    {
        Local_Temp = Local_Password[Local_PasswordSize];
        if(Local_Temp == '\n')
        {
            break;
        }
        Local_PasswordSize++;
    }
    /*Find the length of the inputed password*/
    while(1)
    {
        Local_Temp = Arg_Password[Local_InputedPasswordSize];
        if(Local_Temp == '\0')
        {
            break;
        }
        Local_InputedPasswordSize++;
    }

    /*Check for identically*/
    if(Local_InputedPasswordSize != Local_PasswordSize)
    {
        Local_State = 0;
        *Arg_LoginState = Local_State;
    }
    else
    {
        for(Local_LoopIterator = 0; Local_LoopIterator < Local_InputedPasswordSize; Local_LoopIterator++)
        {
            if(Local_Password[Local_LoopIterator] != Arg_Password[Local_LoopIterator])
            {
                Local_State = 0;
                *Arg_LoginState = Local_State;
                break;
            }
        }
    }

}

int Authent_ValidateStudentData(Student *Arg_StudentArr[], int Arg_ID, char *Arg_Password, int Arg_StudentsNum)
{
    int Local_Iterator = 0;
    char Local_Temp;
    int Local_PasswordSize = 0;
    int Local_InputedPasswordSize = 0;
    int Local_State = 1;
    int Local_InputedIDNum;

    for(Local_Iterator = 0; Local_Iterator < Arg_StudentsNum; Local_Iterator++)
    {
        if((*Arg_StudentArr)[Local_Iterator].id == Arg_ID)
        {
            Local_InputedIDNum = Local_Iterator;
            /*Find the length of the password*/
            while(1)
            {
                Local_Temp = (*Arg_StudentArr)[Local_Iterator].pass[Local_PasswordSize];
                if(Local_Temp == '\0')
                {
                    break;
                }
                Local_PasswordSize++;
            }
            /*Find the length of the inputed password*/
            while(1)
            {
                Local_Temp = Arg_Password[Local_InputedPasswordSize];
                if(Local_Temp == '\0')
                {
                    break;
                }
                Local_InputedPasswordSize++;
            }

            /*Check for identically*/
            if(Local_InputedPasswordSize != Local_PasswordSize)
            {
                Local_State = 0;
            }
            else
            {
                for(Local_Iterator = 0; Local_Iterator < Local_InputedPasswordSize; Local_Iterator++)
                {
                    if((*Arg_StudentArr)[Local_InputedIDNum].pass[Local_Iterator] != Arg_Password[Local_Iterator])
                    {
                        Local_State = 0;
                        break;
                    }
                }
            }
        }
    }

    return Local_State;
}
