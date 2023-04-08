GCC = gcc -g -Wall -Wextra

vpath %.h include
vpath %.c src
vpath %.o obj

all : 
	mkdir obj
	make exe
	

%.o : %.c
	$(GCC) -c $< -Iinclude

exe : main.o tree.o auto_completion.o menu.o dico.o
	$(GCC) main.o tree.o auto_completion.o menu.o dico.o -o exe
	mv $^ ./obj

clean :
	rm -r ./obj exe

