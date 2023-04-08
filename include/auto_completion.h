#include<stdio.h>
#include<stdbool.h>
#include"tree.h"
#include"dico.h"

bool print_most_used(int number, List *list);
void extract_words_from_node(List *list, Node *node);
void print_words_from_string(Root* root, char *string, int number, List *ht[HASH_SIZE]);
int size_of_list(List *list);
void propose_words_to_add(Root *root, List *list, List *ht[HASH_SIZE], char *string, int number);
