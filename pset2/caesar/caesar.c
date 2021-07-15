#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string caesar_crypt(string str, int rotate);
char rotate_alphabet(char c, int rotate);
bool is_letter(char c);
bool is_str_int(string str);
int normalize_int(int i, int max);

int main(int argc, string argv[])
{
    // Check if there is an argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; // Return if none
    }

    string arg = argv[1];

    if (!is_str_int(arg))
    {
        printf("Usage: ./caesar key\n");
        return 2;
    }

    int key = atoi(arg);

    // Get input from user
    string str = get_string("plaintext: ");

    // TODO: get encrypted string
    string cipher = caesar_crypt(str, normalize_int(key, 26));

    // TODO: print string
    printf("ciphertext: %s\n", cipher);
}

// Our main crypt function
string caesar_crypt(string str, int key)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (is_letter(str[i]))
        {
            str[i] = rotate_alphabet(str[i], key);
        }
    }

    printf("str: %s\n", str);

    return str;
}

// Rotate our alphabet
char rotate_alphabet(char c, int key)
{
    int i = (int) c;

    int r;

    // Check if character is upper ow lower
    // Also check if char + key is over max limit
    if (isupper(c))
    {
        if (i + key > 'Z')
        {
            r = ((i + key) % 91) + 65;
        }
        else
        {
            r = i + key;
        }
    }
    if (islower(c))
    {
        if (i + key > 'z')
        {
            r = ((i + key) % 123) + 97;
        }
        else
        {
            r = i + key;
        }
    }

    return (char) r;
}

// Get letters
bool is_letter(char c)
{
    return c >= 'A' && c <= 'z';
}

// Check if string is integer
bool is_str_int(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }

    return true;
}

// Check if key is over our max, if yes, normalize it
int normalize_int(int i, int max)
{
    if (i < max)
    {
        return i;
    }

    int d = i / max;
    i -= d * max;

    return i;
}