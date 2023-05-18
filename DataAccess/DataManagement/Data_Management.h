#ifndef Data_Management
#define Data_Management
#include"../Student_Struct.h"
/**
 * @file Data_Management.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with student data in a dynamic array.
 * @version 0.1
 * @date 2023-05-15
 */
int DDMN_nAddStudent(Student*ptr_aStudent[],int cpy_nNum,Student cpy_sNewStudent);

void DDMN_vEditStudentGrade(Student*ptr_aStudent[],float cpy_fGrade,int cpy_nId,int cpy_nNum);

int DDMN_nDeleteStudent(Student*ptr_aStudent[],int cpy_nId,int cpy_nNum);

void DDMN_vViewStudentRecord(Student*ptr_aStudent[],int cpy_nId,int cpy_nNum);

void DDMN_vViewAllRecord(Student*ptr_aStudent[],int cpy_nNum);
#endif
