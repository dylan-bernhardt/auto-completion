#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"tree.h"

void init_tree(Root *root)
{
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
    int i = letter;
    return i%26;
}

void add_letter_to_node(Node *node, char letter)
{
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
    Node *cur = root.branches[key(word[0])];
    for(int i=1; i<(int)strlen(word); i++)
    {
        add_letter_to_node(cur, word[i]);
        cur = cur->branches[key(word[i])];
    }
    strcpy(cur->word, word);
    cur->nb_of_use++;
}

void branch_words_from_a_file(Root root, char *file_path)
{
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




