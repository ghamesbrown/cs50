// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
#define N 17576

// Global variable that keeps track of the size
int dySize = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
	unsigned int hashVal = hash(word);

	node *locate = table[hashVal];

	while(locate != NULL)
	{
		if(strcasecmp(word, locate->word) == 0)
		{
			return true;
		}
		locate = locate->next;
	}
	return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
	if(word == NULL)
		return 0;

	const int prime = 37;
	unsigned int hashVal = 0;

	for(int i = 0, len = strlen(word); i < len; i++)
	{
		hashVal = prime * hashVal + tolower(word[i]);
	}
	return hashVal % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
	FILE *file = fopen(dictionary,"r");
	
	if(file == NULL)
		return false;

	char word[LENGTH + 1];

	while(fscanf(file, "%s", word) != EOF)
	{
		node *new = malloc(sizeof(node));
		
		strcpy(new->word, word);

		unsigned int hashVal = hash(word);

		new->next = table[hashVal];
		table[hashVal] = new;
		dySize++;
	}
	return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
	return dySize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
	for(int i = 0; i < N; i++)
	{
		node *list = table[i];
		while(list != NULL)
		{
			node *temp = list->next;
			free(list);
			list = temp;
		}
	}
	return true;
}
