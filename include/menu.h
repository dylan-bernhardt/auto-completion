#include"tree.h"
#include"auto_completion.h"

void start();
    /*
    prints a message at the start of the application
    */

void delayed_print(char *string, int ms);
   /*
    prints the string in argument with a delay for each caracter
    */

int delay(int milliseconds);
    /*
    inits the delay of printing
    */

void clear();
    /*
    prints the head of the application
    */

int choices(int ms);
    /*
    prints all the choices the user has 
    */

void my_app();
    /*
    while he doesn't want to quit, the user can use the application
    */