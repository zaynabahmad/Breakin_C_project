main.o: main.c
	gcc -c main.c -o main.o

Menu.o: UserInterface/Menu/Menu_program.c UserInterface/Menu/Menu_interface.h
	gcc -c UserInterface/Menu/Menu_program.c -o Menu.o

Output.o: UserInterface/IO/Output_program.c UserInterface/IO/Output_interface.h
	gcc -c UserInterface/IO/Output_program.c -o Output.o

Input.o: UserInterface/IO/Input_program.c UserInterface/IO/Input_interface.h
	gcc -c UserInterface/IO/Input_program.c -o Input.o

Authentication.o: Application/Authentication/Authentication_program.c Application/Authentication/Authentication_interface.h
	gcc -c Application/Authentication/Authentication_program.c -o Authentication.o

All: main.o Menu.o Output.o	Input.o Authentication.o
	gcc main.o Menu.o Output.o Input.o Authentication.o -o out.exe