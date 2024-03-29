#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef struct_def
#define struct_def 

struct Word{
        /*
    structure that corresponds to a word in the prediction dictionary
    
    @objects
    word : string
        the word included in the dictionary
    nb_of_use : int
        1 if the word has been used one time, 2 if 2... , 0 if not
    */
    char word[20];
    int nb_of_use;
    struct Word* next;
};
typedef struct Word Word;



struct List{
            /*
    structure that corresponds to the head of a chained list in the hash table
    
    @objects
    head : pointer to a word
        contains the adress of the word in the chained list 
    */
    Word *head;
};
typedef struct List List;

#endif

#define HASH_SIZE 3000

void create_hash_table_from_file(List *ht[HASH_SIZE], char *file_name, int nb_letter_to_consider);
    /*
    fills a hash table based on the words in the .txt
    */

void add_word(List *list, Word *word);
    /*
    adds a word in the chained list of the hash table
    */

unsigned long hash_function(char *string, int nb_letter_to_consider);
    /*
    calculates the key of a word, based on the sum of the letters of the string
    */

void print_table(List *ht[HASH_SIZE]);
    /*
    prints the hash table, the words are grouped by the same start of string 
    */

bool is_in_table(List *ht[HASH_SIZE], char *string, int nb_letter_to_consider);
    /*
    returns the presence of a word in the hash table as a bolean
    */

void free_table(List *ht[HASH_SIZE]);
    /*
    frees the hash table from the data, ans allows the filling of it with a new key
    */

void delete_element(List * list);
    /*
    deletes all the words of a chained list
    */

void init_table(List *ht[HASH_SIZE]);
    /*
    inits an empty hash table
    */