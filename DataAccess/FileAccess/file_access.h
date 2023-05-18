#ifndef FILE_ACCESS
#define FILE_ACCESS
#include"../student_struct.h"

/**
 * @file File_Access.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with data in DataBase.
 * @version 0.1
 * @date 2023-05-15
 */
void DFIL_vDeleteAllRec(void);

void DFIL_vWriteStudentRec(Student cpy_sStudent);

int DFIL_nReadStudentRec(Student**ptr_aStudent);

char* DFIL_pReadAdminPass(void);

void DFIL_vWriteAdminPass(char *cpy_pAdminPass);
#endif