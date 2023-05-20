#ifndef AUTHENTICATION_INTERFACE_H_
#define AUTHENTICATION_INTERFACE_H_

void Authent_ValidateAdminData(char *Arg_Password, int *Arg_LoginState);

int Authent_ValidateStudentData(Student *Arg_StudentArr[], int Arg_ID, char *Arg_Password, int Arg_StudentsNum);

#endif
