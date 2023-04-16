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
    /*
    inits a tree

    @parameters
    root : Root *
        the root of the tree the user wants to init
    */

void init_node(Node *node, char letter);
    /*
    inits a node from a letter

    @parameters
    node : Node *
        the node the user wants to init
    letter : char
        the letter that will correspond to the node
    */

int key(char letter);
    /*
    generates a specific key for each letter of the alphabet

    @parameters
    letter : char
        the letter 

    @return
        the key associated to the letter
    */

void add_letter_to_node(Node *node, char letter);
    /*
    branches a new node on an existing node

    @parameters
    node : Node *
        the existing node
    letter : char
        the letter that correspond to the future node
    */

void hook_word(Root root, char *word);
    /*
    adds a word to an exisiting tree

    @parameters
    root : Root
        the root of the tree
    word : string
        the word the users wants to add to the tree
    */

void branch_words_from_a_file(Root root, char *file_path);
    /*
    from a file that contains words, fills the trees with these

    @parameters
    root : Root
        the root of the tree the user wants to fill
    file_path : string
        the path of the file to read
    */

void browse_tree(Root *root);
    /*
    prints all the words included in a tree, by browsing it until the last leaf, and then going back up 
    */

void browse_subtree(Node *node);
    /*
    prints all the words included in a subtree, by browsing it until the last leaf, and then going back up 
    */

bool is_in_tree(Root *root, char *string);
    /*
    returns the presence of a word in the tree, as a boolean  
    */
    