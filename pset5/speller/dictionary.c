// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

int dict_size = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int val = 0;

    // Get first two letters
    for (int i = 0; i < 2; i++) {
        val += toupper(word[i]) - 65;
    }

    // TODO
    return val;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict_pointer = fopen(dictionary, "r");

    // Check if null
    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // Initialise word array
    char next_word[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(dict_pointer, "%s", next_word) != EOF)
    {
        // Create new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // copy word into node using strcopy
        strcpy(n->word, next_word);

        // Hash word to obtain hash value
        int hash_value = hash(next_word);

        // Insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }

    // Close file
    fclose(dict_pointer);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
