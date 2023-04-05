dico.o : dico.c dico.h
	gcc -c dico.c

tree.o : tree.h tree.c
	gcc -c tree.c

auto_completion.o : auto_completion.h auto_completion.c
	gcc -c auto_completion.c

main.o : tree.h main.c
	gcc -c main.c

menu.o : menu.c menu.h tree.h auto_completion.h
	gcc -c menu.c

exe : main.o tree.o auto_completion.o menu.o dico.o
	gcc main.o tree.o auto_completion.o menu.o dico.o -o exe

