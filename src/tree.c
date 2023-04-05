#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"tree.h"

void init_tree(Root *root)
{
    /*
    inits a tree

    @parameters
    root : Root *
        the root of the tree the user wants to init
    */
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i =0; i<26; i++)
    {
        Node *node=malloc(sizeof(Node));
        init_node(node, alphabet[i]);
        root->branches[key(alphabet[i])] = node;
    }
    return;
}

void init_node(Node *node, char letter)
{
    /*
    inits a node from a letter

    @parameters
    node : Node *
        the node the user wants to init
    letter : char
        the letter that will correspond to the node
    */
    node->letter = letter;
    node->nb_of_use=0;
    for(int i=0; i<26; i++)
    {
        node->branches[i] = NULL;
    }
    return;
}


int key(char letter)
{
    /*
    generates a specific key for each letter of the alphabet

    @parameters
    letter : char
        the letter 

    @return
        the key associated to the letter
    */
    int i = letter;
    return i%26;
}

void add_letter_to_node(Node *node, char letter)
{
    /*
    branches a new node on an existing node

    @parameters
    node : Node *
        the existing node
    letter : char
        the letter that correspond to the future node
    */
    if(!(node->branches[key(letter)]))
    {
        Node *new_node = malloc(sizeof(Node));
        init_node(new_node, letter);
        node->branches[key(letter)] = new_node;
    }
    return;
}


void hook_word(Root root, char *word)
{
    /*
    adds a word to an exisiting tree

    @parameters
    root : Root
        the root of the tree
    word : string
        the word the users wants to add to the tree
    */
    Node *cur = root.branches[key(word[0])];
    for(int i=1; i<strlen(word); i++)
    {
        add_letter_to_node(cur, word[i]);
        cur = cur->branches[key(word[i])];
    }
    strcpy(cur->word, word);
    cur->nb_of_use++;
}

void branch_words_from_a_file(Root root, char *file_path)
{
    /*
    from a file that contains words, fills the trees with these

    @parameters
    root : Root
        the root of the tree the user wants to fill
    file_path : string
        the path of the file to read
    */
    FILE *f = fopen(file_path,"r");
    char line[20];
    while(fscanf(f, "%s", line)==1)
    {
        hook_word(root, line);
    }
    return ;
}

void browse_tree(Root *root)
{
    for(int i=0; i<26; i++)
    {
        browse_subtree(root->branches[i]);
    }
    return;
}

void browse_subtree(Node *node)
{
    if(node->nb_of_use!=0) printf("%s---%d\n", node->word, node->nb_of_use);
    if(!node)
    {
        return;
    }
    for(int i =0; i<26; i++)
    {
        if(node->branches[i])
        {
            browse_subtree(node->branches[i]);
        }
    }
    
}


bool is_in_tree(Root *root, char *string)
{
    bool flag = false;
    Node *node = root->branches[key(string[0])];
    for(int i=1; string[i]&&node;i++) node=node->branches[key(string[i])];
    if(node)
    {
        if(strcmp(node->word,string)==0) flag = true;
    }
    return flag;
    
}




