#ifndef STUDENT_H
#define STUDENT_H
#include"../../DataAccess/student_struct.h"
/**
 * @file student.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with student mode.
 * @version 0.1
 * @date 2023-05-18
 */
void ASTU_vViewRecord(Student *ptr_aStudents[],int cpy_nNum);

void ASTU_vEditPass(Student *ptr_aStudents[],int cpy_nNum);

void ASTU_vEditName(Student *ptr_aStudents[],int cpy_nNum);
#endif