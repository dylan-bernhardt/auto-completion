#include<stdio.h>
#include<stdbool.h>
#include"tree.h"
#include"dico.h"

bool print_most_used(int number, List *list);
    /*
    prints a number of words that start with the same string as informed, in the most used order. 
    If there are too many words in the tree, only the most frequently used are wroten down by the application. Else, all the words available are wroten down. 
    */

void extract_words_from_node(List *list, Node *node);
    /*
    returns all the words available from a leaf in the tree. 
    The tree is browsed in all directions to find all the words. 
    */

void print_words_from_string(Root* root, char *string, int number, List *ht[HASH_SIZE]);
    /*
    prints all the words that start with the same string as informed. The first words printed are taken from the prediction dictionary. 
    If not enough words are found, the application will look for more words in the french dictionary. 
    Until enough words are confirmed by the user, or if there are no more words in the french dictionary, the application will suggest new words. 
    */

int size_of_list(List *list);
    /*
    returns the number of words which start with the same string 
    */

void propose_words_to_add(Root *root, List *list, List *ht[HASH_SIZE], char *string, int number);
    /*
    prints all the words left in the french dictionary that start with the same string as informed, but which are not in the prediction dictionary.
    The user can choose or not to add the words suggested by the application
    */
