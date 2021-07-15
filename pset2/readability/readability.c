#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int get_text_grade(string text);
int get_letters(string text);
int get_sentences(string text);
int get_words(string text);
bool is_letter(char c);

int main(void)
{
    // Get text input
    string text = get_string("Text: ");

    // Calculate grade based on text
    int grade = get_text_grade(text);

    // Print grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Function to get text grade
int get_text_grade(string text)
{
    // We made functions to get letters, word, and sentences
    int letters = get_letters(text);
    int sentences = get_sentences(text);
    int words = get_words(text);

    // Make it out of 100 words
    float l = (letters * 100) / (float) words;
    float s = (sentences * 100) / (float) words;

    // Enter variables into Coleman-Liau formula
    float grade = round(0.0588 * l - 0.296 * s - 15.8);

    return (int) grade;
}

// Get letters
int get_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!is_letter(text[i]))
        {
            continue;
        }

        letters++;
    }

    return letters;
}

// Get sentences
int get_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

int get_words(string text)
{
    int words = 0;
    bool is_word_before = false;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!is_letter(text[i]) && text[i] != 39 && text[i] != 45 && text[i] != ',')
        {
            is_word_before = false;
            continue;
        }
        else
        {
            if (!is_word_before && is_letter(text[i]))
            {
                words++;
            }

            is_word_before = true;
        }
    }

    return words;
}

// Get letters
bool is_letter(char c)
{
    return c >= 'A' && c <= 'z';
}