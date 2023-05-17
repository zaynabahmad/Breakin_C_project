#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../Student_struct.h"
#include"../MemoryManagement/Memory_Management.h"

/*
*File_Access.h
*Moamen eltony
*This file contains functions that deal with data in DataBase.
*Version 1.0
*2023-05-15
*/


/*
Use this function to delete records from the database.
*/
void FileAccess_voidDeleteAllRec(void)
{
	fclose(fopen("DataAccess/FileAccess/Student_Data.csv", "w"));
}

/*
Use this function to add students to the database. 
It takes student structure as argument.
*/

void FileAccess_voidWriteStudentRec(Student Arg_studentRecord)
{
	FILE *Local_file;
	Local_file = fopen("DataAccess/FileAccess/Student_Data.csv","a");

	if(Local_file == NULL)
	{
		printf("FileAccess_voidDeleteAllRec: Error opening file.\n");

		return;
    }

    fprintf(Local_file,
			"%s,%s,%.2f,%d,%d,%c\n",
			Arg_studentRecord.name,
			Arg_studentRecord.pass,
			Arg_studentRecord.grade,
			Arg_studentRecord.id,
			Arg_studentRecord.age,
			Arg_studentRecord.gender);

    if(ferror(Local_file))
    {
		printf("FileAccess_voidDeleteAllRec: Error writing to file.\n");
    }

    fclose(Local_file);
}

/*
Use this function to read all students data from the database.
It takes a pointer to an array of students as an argument.
return number of the student

*/

int FileAccess_voidReadStudentRec(Student**Arg_Arr)
{
    FILE *Local_file;
    Local_file = fopen("DataAccess/FileAccess/Student_Data.csv", "r");

    if (Local_file == NULL)
    {
		printf("FileAccess_voidReadStudentRec: Error opening file.\n");

		return 0;
    }

    Student Local_studentTemp;

    char *Local_pcPass;
	char *Local_pcName;

	int size=0;

	while(!feof(Local_file))
    {
		int num = 0;

		Memory_Management_Allocate_SudentName(&Local_pcName);
        Memory_Management_Allocate_SudentName(&Local_pcPass);

		num = fscanf(Local_file,
				   "%49[^,],%49[^,],%f,%d,%d,%c\n",
				   Local_pcName,
				   Local_pcPass,
				   &Local_studentTemp.grade,
				   &Local_studentTemp.id,
				   &Local_studentTemp.age,
				   &Local_studentTemp.gender);

		Memory_Management_Resize_SudentName(&Local_pcName);
		Memory_Management_Resize_SudentName(&Local_pcPass);

		Local_studentTemp.name = Local_pcName;
		Local_studentTemp.pass = Local_pcPass;

		Local_pcName = NULL;
		Local_pcPass = NULL;

		if((num != 6) && (!feof(Local_file)))
		{
			printf("FileAccess_voidReadStudentRec: File format incorrect.\n");

			return 0;
		}

        Memory_Management_Allocate_Student_Memory(Arg_Arr,size);
		*(*(Arg_Arr)+size)=Local_studentTemp;
		size++;

    }
    fclose(Local_file);
    return size;
}

/*
Use this function to read admin passwords from the database. 
It returns the admin password as a string.
*/

char* FileAccess_voidReadAdminPass(void)
{
    FILE *Local_file;
    Local_file = fopen("DataAccess/FileAccess/Admin_Password.csv", "r");
    char *Local_Admin_Pass=malloc(50*sizeof(char));
    fscanf(Local_file,"%49[^,]",Local_Admin_Pass);
    Local_Admin_Pass=(char*)realloc(Local_Admin_Pass,strlen(Local_Admin_Pass)+1);
    if(ferror(Local_file))
    {
		printf("FileAccess_voidReadAdminPass: Error writing to file.\n");
    }
    fclose(Local_file);
    return Local_Admin_Pass;
}
/*
Use this function to update the admin record.
It takes a char pointer as an argument.
*/
void FileAccess_voidWriteAdminPass(char *Arg_AdminPass)
{
    FILE *Local_file;
    Local_file = fopen("DataAccess/FileAccess/Admin_Password.csv", "w");
    if(Local_file == NULL)
	{
		printf("FileAccess_voidDeleteAllRec: Error opening file.\n");

		return;
    }
     fprintf(Local_file,"%s\n",Arg_AdminPass);
     fclose(Local_file);
}
