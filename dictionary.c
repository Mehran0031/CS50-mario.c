#include <stdbool.h>
#include <ctype.h>
#include "dictionary.h"
#include <string.h>
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
} 
node;

// my variables:
node* head = NULL; // important!
char word[LENGTH + 1];
node* hashtable[27];
int cont_words = 0;

// my functions:
void insert(char* n);
int hash_function(char* key);


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int len = strlen(word) + 1;
    
    // get memory for this word:
    char* lower_word = malloc(sizeof(char) * len);
    // if something go wrong:
    if (lower_word == NULL) return false;
    
    // convert lower_word to lowercase:
    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {  
            lower_word[i] = tolower(word[i]);
        }
        else
        {
            lower_word[i] = word[i];
        }
    }

    // create new element and add to begin:
    node* new = malloc(sizeof(node));
    // hash it:
    int hash_0 = toupper(lower_word[0]) - 'A';
    int hash_hash = hash_0 % 27;

    // put head of list to new element:
    new = hashtable[hash_hash];
    
    // check all element in list:
    while (new != NULL)
    { 
        if (strcmp(new->word, lower_word) == 0) 
        {
            // if word exist in list, return true:
            return true;
        }
        // move:
        new = new->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool load(const char* dictionary)
{
        FILE* fp = fopen(dictionary, "r");
        if (!fp) 
        {
    		printf("Something go bad in %s.\n", dictionary);
    		return false;
    	}
              
        while (fscanf(fp, "%s\n", word) != EOF)
        {            
            // create new element and add to begin:
            node* new = malloc(sizeof(node));
            strcpy(new->word, word);
            new->next = head;
            head = new;
            
            // hash it:
            int hash_hash = hash_function(word);
            // if hash_hash index doesn't exists in hashtable:
            // add new element to array:
            if (hashtable[hash_hash] == NULL) 
            { 
                hashtable[hash_hash] = new;
                new->next = NULL;
            }
            
            // if hash_hash index allready exists in hashtable:
            // add new element to begin of list:
            else 
            {
                new->next = hashtable[hash_hash];
                hashtable[hash_hash] = new;
            }
            cont_words++;
        }
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return cont_words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
   
    for (int i = 0; i < 27; i++)
    {
        // go to head of the list:
        node* header = hashtable[i];
        // if need to save value, use this:
        // char value = hashtable[i]->word;

        // pop:
        while (header != NULL)
        {
            node* tmp = header;
            header = header->next;
            free(tmp);
            return true;
        }

        // set the head to NULL in hashtable:
        hashtable[i] = NULL;
    }

    return false;
}

////////////////////////////////////////////
/*              MY FUNCTION:              */
////////////////////////////////////////////

int hash_function(char* key)
{
  int hash = toupper(key[0]) - 'A';
  return hash % 27;
}