#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include"auto_completion.h"
#include"dico.h"
#include<unistd.h>



bool print_most_used(int number, List *list)
{
    /*
    prints a number of words that start with the same string as informed, in the most used order. 
    If there are too many words in the tree, only the most frequently used are wroten down by the application. Else, all the words available are wroten down. 
    */
    Word *cur = list->head;
    int size = size_of_list(list), k=0;
    if(number > size)
    {
        puts("Not enough words found, I only found :\n");
        while(cur)
        {
            printf("\t\t[ %d ] . %s\t\t---%d\n", k++,cur->word, cur->nb_of_use);
            cur = cur->next;
            
            
        }
        return false;
    }
    else
    {
        int max=0, j=-1;
        Word *most_used_word;
        for(int i=0; i<number; i++)
        {
            while(cur)
            {
                if(cur->nb_of_use>max)
                {
                    max = cur->nb_of_use;
                    most_used_word=cur;
                }
                cur=cur->next;
            }
            printf("[ %d ] . %s\t\t---%d\n",i+1, most_used_word->word, most_used_word->nb_of_use);
            printf("\t\t");
            most_used_word->nb_of_use=j;
            max = 0;
            j--;
            cur = list->head;
        }
    }
    return true;
}


void extract_words_from_node(List *list, Node *node)
{
    /*
    returns all the words available from a leaf in the tree. 
    The tree is browsed in all directions to find all the words. 
    */
    if(node->nb_of_use!=0) 
    {
        Word *word = malloc(sizeof(Word));
        strcpy(word->word,node->word);
        word->nb_of_use=node->nb_of_use;
        word->next = list->head;
        list->head = word;
       
    }
    if(!node)
    {
        return;
    }
    for(int i =0; i<26; i++)
    {
        if(node->branches[i])
        {
            extract_words_from_node(list, node->branches[i]);
        }
    }
}


void print_words_from_string(Root* root, char *string, int number, List *ht[HASH_SIZE])
{
    /*
    prints all the words that start with the same string as informed. The first words printed are taken from the prediction dictionary. 
    If not enough words are found, the application will look for more words in the french dictionary. 
    Until enough words are confirmed by the user, or if there are no more words in the french dictionary, the application will suggest new words. 
    */
    Node * node;
    node = root->branches[key((string[0]))];
    List list;
    list.head = NULL;
    int k =1;
    while(string[k] && node->branches[key(string[k])]) 
    {
        node = node->branches[key(string[k])];
        k++;
    }
    if(k>=(int)strlen(string))   extract_words_from_node(&list, node);

    Word *cur = list.head;
    
    bool enough = print_most_used(number, &list);
    if(enough && k>=(int)strlen(string))
    {
        int choice;
        printf("\n\n\t\tWhich one do you want to choose ?\n\t\t");
        scanf("%d", &choice);
        while(choice>number) 
            {
                printf("\t\t Unvalid choice, try again\n\t\t");
                scanf("%d", &choice);
            }
        while(cur->nb_of_use != choice*(-1)) 
        {
            cur=cur->next;
        }
        printf("\n\n\t\tYou chose : %s\n\n", cur->word);
        usleep(2000000);
        node = root->branches[key(cur->word[0])];
        for(int i =1; i<(int)strlen(cur->word); i++) node=node->branches[key(cur->word[i])];
        node->nb_of_use++;
    }
    else
    {
        propose_words_to_add(root,&list,ht,string,number);
    }

}

int size_of_list(List *list)
{
    /*
    returns the number of words which start with the same string 
    */
    Word *word = list->head;
    int k=0;
    while(word) 
    {
        word=word->next;
        k++;
    }
    return k;
}



void propose_words_to_add(Root *root, List *list, List *ht[HASH_SIZE], char *string, int number)
{
    /*
    prints all the words left in the french dictionary that start with the same string as informed, but which are not in the prediction dictionary.
    The user can choose or not to add the words suggested by the application
    */
    unsigned long key = hash_function(string, strlen(string));
    Word *word1 = ht[key]->head, *word2;
    bool flag ;
    printf("\n\t\tI need to complete the dico...and add %d words ...\n", number-size_of_list(list));
    usleep(3000000);
    int word_found =0,same, choice;
    while(word1 && word_found!=number-size_of_list(list))
    {
        flag = true;
        same = 0;
        for(int k=0; k<(int)strlen(string); k++)
        {
            if(word1->word[k]==string[k]) same++;         
        }
        if(same == (int)strlen(string))
        {
            word2 = list->head;
            
            while(word2)
            {
                if(strcmp(word2->word, word1->word)==0) flag = false;
                word2 = word2->next;
            }
            if(flag) 
            {
                system("clear");
                fputs("######################################################################\n"
    "           Algo Prog Project\n"
    "######################################################################", stdout);
                puts("\n\n");
                fputs("\t\t", stdout);
                printf("\n\t\tDo you want to add %s\n\n\t\t[ 0 ] . No\n\n\t\t[ 1 ] . Yes\n", word1->word);
                scanf("%d",&choice);
                if(choice)
                {
                    hook_word(*root, word1->word);
                    word_found++;
                    

                }
                
           }
        }

        word1 = word1->next;
    }

    puts("\n There is no more words or the dico is filled...");
    usleep(2000000);
    

}
