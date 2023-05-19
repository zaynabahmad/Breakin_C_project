#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct student
{
    float grade;
    int id;
    int age;
    char *name;
    char *pass;
    char gender;
}
Student;

typedef struct admin
{
    char *username;
    char *pass;
}
Admin;

#endif