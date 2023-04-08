#include"menu.h"
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tree.h"
#include"auto_completion.h"
#include"dico.h"


void start()
{
    clear();
    delayed_print("Welcome to our app !\n\n", 50);
    fputs("            ",stdout);
    delayed_print("Please press enter to start the app...", 50);
    puts("\n\n\n######################################################################");
    getchar();
    clear();    
}

void delayed_print(char *string, int ms)
{
    int k =0;
    while(string[k])
    {
        printf("%c", string[k]);
        fflush(stdout);
        delay(ms);
        k++;
    }
}

int delay(int milliseconds)
{
    return usleep(milliseconds*1000);
}

void clear()
{
    system("clear");
    fputs("######################################################################\n"
    "           Algo Prog Project\n"
    "######################################################################", stdout);
    puts("\n\n");
    fputs("\t\t", stdout);
    return ;
}

int choices(int ms)
{
    fputs("\t\t", stdout);
    delayed_print("And then...", ms);
    fputs("\n\n\t\t", stdout);
    delayed_print("1. Test our auto-completion program...", ms);
    fputs("\n\n\t\t", stdout);
    delayed_print("2. Add a word to the prediction dictionnary...", ms);
    fputs("\n\n\t\t", stdout);
    delayed_print("3. Remove a word from the prediction dictionnary...", ms);
    fputs("\n\n\t\t", stdout);
    delayed_print("4. You are done and you want to quit...", ms);
    fputs("\n\n\t\t", stdout);
    delayed_print("5. Relax with some music...", ms);
    puts("\n");
    int input;
    fscanf(stdin, "%d", &input);
    return input;
    
}

void my_app()
{
    start();
    char _string[50];
    Root root;
    init_tree(&root);
    branch_words_from_a_file(root, "./txt/mots_courants.txt");
    List *ht[HASH_SIZE];
    init_table(ht);
    bool quit = false;
    while(!quit)
    {
        int a=choices(30);
        switch(a)
        {
            case 1:
                clear();
                delayed_print("Please type :", 30);
                fputs("\n\n\t\t",stdout);
                scanf("%s", _string);
                create_hash_table_from_file(ht, "./txt/dictionnaire.txt", strlen(_string));
                clear();
                fputs("Words found :\n\n\t\t", stdout);
                print_words_from_string(&root, _string, 3, ht);
                free_table(ht);
                clear();
                break;
            case 2:
                clear();
                delayed_print("Please type :", 30);
                fputs("\n\n\t\t",stdout);
                scanf("%s", _string);
                clear();
                create_hash_table_from_file(ht, "./txt/dictionnaire.txt", 10);
                if(is_in_tree(&root,_string)) 
                    {
                        delayed_print("The word is already in the dictionnary", 30);
                        delay(2000);
                    }
                else
                {
                    if(is_in_table(ht,_string,10))
                    {
                        hook_word(root, _string);
                        delayed_print("The word has been added with success.",30);
                        delay(2000);
                        
                    }
                    else
                    {
                        delayed_print("The word is not in the french dictionnary, are you sure that you want to add it ?\n\n",30);
                        delayed_print("\n\n\t\t[ 1 ]. Yes\n\t\t[ 2 ]. No\n",30);
                        int choice;
                        scanf("%d",&choice);;
                        if(choice) 
                        {
                            clear();
                            hook_word(root, _string);
                            delayed_print("The word has been added with success.",30);
                            delay(2000);
                        }

                    }
                    
                }
                free_table(ht);
                clear();
                break;      
            case 3:
                clear();
                delayed_print("Please type :", 30);
                fputs("\n\n\t\t",stdout);
                scanf("%s", _string);
                clear();
                if(is_in_tree(&root, _string)) 
                {
                    Node *node = root.branches[key(_string[0])];
                    for(int i=1; _string[i]; i++) node=node->branches[key(_string[i])];
                    node->nb_of_use=0;
                    delayed_print("The word has been delete with success", 30);
                    delay(2000);
                }
                else
                {
                    delayed_print("The word is not in the dictionnary...",30);
                    delay(2000);
                }
                clear();
                break;      
            case 4:
                clear();
                delayed_print("Thanks for using the app, see you soon !", 30);
                puts("\n");
                quit = true;
                break;      
            case 5:
                system("firefox https://www.youtube.com/watch?v=_Yhyp-_hX2s");
                clear();
                break;      

        }
    }


}