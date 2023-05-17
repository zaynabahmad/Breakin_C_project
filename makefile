main.o: main.c
	gcc -c main.c -o main.o

Menu.o: UserInterface/Menu/Menu_program.c UserInterface/Menu/Menu_interface.h
	gcc -c UserInterface/Menu/Menu_program.c -o Menu.o

IO.o: UserInterface/IO/IO_program.c UserInterface/IO/IO_interface.h
	gcc -c UserInterface/IO/IO_program.c -o IO.o

All: main.o Menu.o IO.o
	gcc main.o Menu.o IO.o -o out.exe