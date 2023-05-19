#ifndef ADMIN_H
#define ADMIN_H
#include"../../DataAccess/student_struct.h"
/**
 * @file admin.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with admin mode.
 * @version 0.1
 * @date 2023-05-18
 */

void AADM_vAddStudent(Student *ptr_aStudents[],int *ptr_nNum);

void AADM_vRemoveStudent(Student *ptr_aStudents[],int *ptr_nNum);

void AADM_vViewStudent(Student *ptr_aStudents[],int cpy_nNum);

void AADM_vViewAllStudent(Student *ptr_aStudents[],int cpy_nNum);

void AADM_vEditAdminPass();

void AADM_vEditStudentGrade(Student *ptr_aStudents[],int cpy_nNum);

#endif