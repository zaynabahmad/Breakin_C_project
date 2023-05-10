#include<stdio.h>
#include"../../st_struct.h"
void cs_data()
{
    fclose(fopen("student_data.txt", "w"));
}
//we use ws_data function ro add student data to file
void ws_data(stu p_st)
{
    FILE *file;
    file=fopen("student_data.txt","a");
    if (file == NULL)
    {
      printf("Error opening file.\n");
      return;
    }
    fprintf(file,"%s,%s,%.2f,%d,%d,%c\n",p_st.name,p_st.pass,p_st.grade,p_st.id,p_st.age,p_st.gender);
    if (ferror(file))
    {
      printf("Error writing to file.\n");
    }
    fclose(file);
}
//we can use rs_data function to send students data in student_data file to function that add them to array
void rs_data()
{
    FILE *file;
    file = fopen("student_data.txt", "r");
    if (file == NULL)
    {
      printf("Error opening file.\n");
      return;
    }
    stu temp;
    char *s;
    char *a;
    while(!feof(file))
    {
      int num=0;
      s = malloc(50 * sizeof(char));
      a = malloc(50 * sizeof(char));
      num=fscanf(file,"%49[^,],%49[^,],%f,%d,%d,%c\n",a,s,&temp.grade,&temp.id,&temp.age,&temp.gender);
      s = realloc(s, strlen(s) + 1);
      a = realloc(a, strlen(a) + 1);
      temp.name=a;
      temp.pass=s;
      a=NULL;
      s=NULL;
      if (num != 6 && !feof(file))
      {
        printf("File format incorrect.\n");
        return;
      }
      //function that add this student to array
    }
     fclose(file);
}
