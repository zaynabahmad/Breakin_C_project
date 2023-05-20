main.o: main.c
	gcc -c main.c -o main.o

Menu.o: UserInterface/Menu/Menu_program.c UserInterface/Menu/Menu_interface.h
	gcc -c UserInterface/Menu/Menu_program.c -o Menu.o

Output.o: UserInterface/IO/Output_program.c UserInterface/IO/Output_interface.h
	gcc -c UserInterface/IO/Output_program.c -o Output.o

Input.o: UserInterface/IO/Input_program.c UserInterface/IO/Input_interface.h
	gcc -c UserInterface/IO/Input_program.c -o Input.o

Admin.o: Application/Admin/admin.c Application/Admin/admin.h
	gcc -c Application/Admin/admin.c -o Admin.o

Student.o: Application/student/student.c Application/student/student.h
	gcc -c Application/student/student.c -o Student.o

DataManagement.o: DataAccess/DataManagement/data_management.c DataAccess/DataManagement/data_management.h
	gcc -c DataAccess/DataManagement/data_management.c -o DataManagement.o

FileAccess.o: DataAccess/FileAccess/file_access.c DataAccess/FileAccess/file_access.h
	gcc -c DataAccess/FileAccess/file_access.c -o FileAccess.o

MemoryManagement.o: DataAccess/MemoryManagement/memory_management.c DataAccess/MemoryManagement/memory_management.h
	gcc -c DataAccess/MemoryManagement/memory_management.c -o MemoryManagement.o

Authentication.o: Application/Authentication/Authentication_program.c Application/Authentication/Authentication_interface.h
	gcc -c Application/Authentication/Authentication_program.c -o Authentication.o

All: main.o Menu.o Output.o	Input.o Authentication.o Admin.o Student.o DataManagement.o FileAccess.o MemoryManagement.o
	gcc main.o Menu.o Output.o Input.o Authentication.o Admin.o Student.o DataManagement.o FileAccess.o MemoryManagement.o -o out.exe