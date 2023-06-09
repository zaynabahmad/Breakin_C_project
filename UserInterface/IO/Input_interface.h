#ifndef INPUT_INTERFACE_H_
#define INPUT_INTERFACE_H_

#define INPUT_ADMIN_TYPE        1u
#define INPUT_STUDENT_TYPE      2u


char Input_ScanNumber(void);
void Input_ScanAdminInfromation(void);
char Input_ScanMenuChoice(char **Arg_ChoicesArr, int Arg_ListSize, int *Arg_ChoiceIndicator);
char Input_ScanLoginData(char Arg_UserType, int *Arg_LoginState);
char Input_ScanStudentLoginData(Student *Arg_StudentArr[], int Arg_StudentsNum, int *Arg_LoginState);

#endif