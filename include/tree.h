#include<stdio.h>
#include<stdbool.h>
#ifndef compile

#define compile

struct Node {
    /*
    structure that corresponds to a leaf of the tree ; every leafs coresponds to a letter

    @objects
    branches : tab
        contains the adress of each branch that comes from this one
    word : string
        the word created by this node and the previous one
    nb_of_use : int
        1 if the word has been used one time, 2 if 2... , 0 if not
    letter : char
        the letter that corresponds to the node 
    */
    struct Node *branches[26];
    char word[20];
    int nb_of_use;
    char letter;
};
typedef struct Node Node;

struct Root {
    /*
    structure that corresponds to the root of the tree

    @objects
    branches : tab
        contains 26 pointers corresponding to the first letter of each words
    */
    struct Node *branches[26];
};
typedef struct Root Root;

#endif

void init_tree(Root *root);
void init_node(Node *node, char letter);
int key(char letter);
void add_letter_to_node(Node *node, char letter);
void hook_word(Root root, char *word);
void branch_words_from_a_file(Root root, char *file_path);
void browse_tree(Root *root);
void browse_subtree(Node *node);
bool is_in_tree(Root *root, char *string);