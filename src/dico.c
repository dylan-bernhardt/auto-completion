#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"dico.h"


unsigned long hash_function(char *string, int nb_letter_to_consider)
{
	int sum=0;
	for(int i=0;string[i] && i<nb_letter_to_consider;i++)
	{
		sum+=string[i];
	}
	return sum%HASH_SIZE;
}

void create_hash_table_from_file(List *ht[HASH_SIZE], char *file_name, int nb_letter_to_consider)
{
	FILE *file=fopen(file_name,"r");
	if(file)
	{
		char string[50];
		while(fscanf(file,"%s",string)==1)
		{
			
			Word *word=(Word *)malloc(sizeof(Word));
			strcpy(word->word,string);
			add_word(ht[hash_function(string,nb_letter_to_consider)],word);
		}
	fclose(file);
	}
}

void print_table(List *ht[HASH_SIZE])
{
	Word *word;
	for(unsigned long i=0;i<HASH_SIZE;i++)
	{
		word=ht[i]->head;
		while(word)
		{
			printf("%s\n",word->word);
			word=word->next;
		}
		printf("*\n");
	}
}

void add_word(List *list, Word *word)
{
	word->next=list->head;
	list->head=word;
}

bool is_in_table(List *ht[HASH_SIZE], char *string, int nb_letter_to_consider)
{
	unsigned long code=hash_function(string,nb_letter_to_consider);

	Word *word;
	word=ht[code]->head;

	while(word)
	{
		if(strcmp(word->word,string)==0)
		{
			return true;
		}
		word=word->next;
		
	}
	return false;
}


void free_table(List *ht[HASH_SIZE])
{
	for(unsigned long i =0; i<HASH_SIZE; i++)
	{
		while(ht[i]->head)
		{
			delete_element(ht[i]);
		}


	}
	return;
}

void delete_element(List * list)
{
	Word *word = list->head;
	if(word)
	{
		list->head = word -> next;
		free(word);
	}
	return;
}


void init_table(List *ht[HASH_SIZE])
{
	for(unsigned long i=0;i<HASH_SIZE;i++)			
		{
			List *list=(List *)malloc(sizeof(List));
			list->head=NULL;
			ht[i]=list;
		}
}