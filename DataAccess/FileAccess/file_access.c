#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../student_struct.h"
#include"../MemoryManagement/memory_management.h"
/**
 * @file File_Access.h
 * @author Moamen eltony
 * @brief This file contains functions that deal with data in DataBase.
 * @version 0.1
 * @date 2023-05-15
 */

/**
 *brief :Use this function to delete records from the database.
 */
void DFIL_vDeleteAllRec(void)
{
	fclose(fopen("DataAccess/FileAccess/student_data.csv", "w"));
}

 /**
 *brief :Use this function to add students to the database.�
 *@param cpy_sStudent:Student Data
 */
void DFIL_vWriteStudentRec(Student cpy_sStudent)
{
	FILE *loc_ptr_file;
	loc_ptr_file = fopen("DataAccess/FileAccess/student_data.csv","a");

	if(loc_ptr_file == NULL)
	{
		printf("FileAccess_voidDeleteAllRec: Error opening file.\n");

		return;
    }

    fprintf(loc_ptr_file,
			"%s,%s,%.2f,%d,%d,%c\n",
			cpy_sStudent.name,
			cpy_sStudent.pass,
			cpy_sStudent.grade,
			cpy_sStudent.id,
			cpy_sStudent.age,
			cpy_sStudent.gender);

    if(ferror(loc_ptr_file))
    {
		printf("FileAccess_voidDeleteAllRec: Error writing to file.\n");
    }

    fclose(loc_ptr_file);
}

 /**
 *brief :Use this function to read all Students data from the database.
 *@param ptr_aStudent:pointer to Students array
 *@return int:number of students
 */
int DFIL_nReadStudentRec(Student**ptr_aStudent)
{
    FILE *loc_ptr_file;
    loc_ptr_file = fopen("DataAccess/FileAccess/student_data.csv", "r");

    if (loc_ptr_file == NULL)
    {
		printf("FileAccess_voidReadStudentRec: Error opening file.\n");

		return 0;
    }

    Student Loc_cpy_sStudentTemp;

    char *Loc_ptr_pPass;
	char *Loc_ptr_pName;

	int cpy_nSize=0;

	do
    {
		int num = 0;

		DMMN_vAllocateSudentName(&Loc_ptr_pName);
        DMMN_vAllocateSudentName(&Loc_ptr_pPass);

		num = fscanf(loc_ptr_file,
				   "%49[^,],%49[^,],%f,%d,%d,%c\n",
				   Loc_ptr_pName,
				   Loc_ptr_pPass,
				   &Loc_cpy_sStudentTemp.grade,
				   &Loc_cpy_sStudentTemp.id,
				   &Loc_cpy_sStudentTemp.age,
				   &Loc_cpy_sStudentTemp.gender);

		DMMN_vResizeSudentName(&Loc_ptr_pName);
		DMMN_vResizeSudentName(&Loc_ptr_pPass);

		Loc_cpy_sStudentTemp.name = Loc_ptr_pName;
		Loc_cpy_sStudentTemp.pass = Loc_ptr_pPass;

		Loc_ptr_pName = NULL;
		Loc_ptr_pPass = NULL;

		if((num != 6) && (!feof(loc_ptr_file)))
		{
			printf("FileAccess_voidReadStudentRec: File format incorrect.\n");

			return 0;
		}

        DMMN_vAllocateStudentMemory(ptr_aStudent,cpy_nSize);
		*(*(ptr_aStudent)+cpy_nSize)=Loc_cpy_sStudentTemp;
		cpy_nSize++;
    }while(!feof(loc_ptr_file));
    fclose(loc_ptr_file);
    return cpy_nSize;
}

 /**
 *brief :Use this function to read admin passwords from the database.
 *@return char*:char pointer to admin password
 */
char* DFIL_pReadAdminPass(void)
{
    FILE *loc_ptr_file;
    loc_ptr_file = fopen("DataAccess/FileAccess/admin_password.csv", "r");
    char *Loc_cpy_pAdminPass=malloc(50*sizeof(char));
    fscanf(loc_ptr_file,"%49[^,]",Loc_cpy_pAdminPass);
    Loc_cpy_pAdminPass=(char*)realloc(Loc_cpy_pAdminPass,strlen(Loc_cpy_pAdminPass)+1);
    if(ferror(loc_ptr_file))
    {
		printf("FileAccess_voidReadAdminPass: Error writing to file.\n");
    }
    fclose(loc_ptr_file);
    return Loc_cpy_pAdminPass;
}

 /**
 *brief :Use this function to update the admin record.
 *@param cpy_pAdminPass:Admin password as string
 */
void DFIL_vWriteAdminPass(char *cpy_pAdminPass)
{
    FILE *loc_ptr_file;
    loc_ptr_file = fopen("DataAccess/FileAccess/admin_password.csv", "w");
    if(loc_ptr_file == NULL)
	{
		printf("FileAccess_voidDeleteAllRec: Error opening file.\n");

		return;
    }
     fprintf(loc_ptr_file,"%s\n",cpy_pAdminPass);
     fclose(loc_ptr_file);
}
