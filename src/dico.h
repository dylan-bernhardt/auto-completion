#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef struct_def
#define struct_def 

struct Word{
    char word[20];
    int nb_of_use;
    struct Word* next;
};
typedef struct Word Word;



struct List{
    Word *head;
};
typedef struct List List;

#endif

#define HASH_SIZE 3000

void create_hash_table_from_file(List *ht[HASH_SIZE], char *file_name, int nb_letter_to_consider);
void add_word(List *list, Word *word);
unsigned long hash_function(char *string, int nb_letter_to_consider);
void print_table(List *ht[HASH_SIZE]);
bool is_in_table(List *ht[HASH_SIZE], char *string, int nb_letter_to_consider);
void free_table(List *ht[HASH_SIZE]);
void delete_element(List * list);
void init_table(List *ht[HASH_SIZE]);