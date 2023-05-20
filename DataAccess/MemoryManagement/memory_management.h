#ifndef Memory_Management
#define Memory_Management
#include "../student_struct.h"
/**
 * @file Memory_Management.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with memory in Heab.
 * @version 0.1
 * @date 2023-05-15
 */
void DMMN_vAllocateSudentName(char **ptr_aName);

void DMMN_vResizeSudentName(char **ptr_aName);

void DMMN_vAllocateStudentMemory(Student *ptr_aStudents[],int cpy_nNum);

void DMMN_vDeleteStudentMemory(Student*ptr_aStudents[],int cpy_nNum);

#endif
