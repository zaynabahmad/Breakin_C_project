#include<stdio.h>
#include<stdlib.h>
#include"DataAccess/FileAccess/File_Access.h"
#include"DataAccess/MemoryManagement/memory_management.h"
#include"DataAccess/DataManagement/Data_Management.h"
#include"DataAccess/Student_Struct.h"
#include"Application/Student/student.h"
#include"Application/Admin/admin.h"
int main()
{
    Student arr;
    arr=(Student*)malloc(1*sizeof(Student));
    int n;
    n=DFIL_nReadStudentRec(&arr);
    /*
    logic
    */
    DFIL_vDeleteAllRec();
    for(int i=0;i<n;i++)
    {
        DFIL_vWriteStudentRec(arr[i]);
        free(arr[i].name);
        free(arr[i].pass);
        arr[i].name=NULL;
        arr[i].pass=NULL;
    }
}
