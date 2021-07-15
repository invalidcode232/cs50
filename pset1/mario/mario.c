#include <stdio.h>
#include <cs50.h>

int get_valid_int(string q, int min);
void generate_pyramid(int height);

int main(void)
{
    // Get pyramid height
    int height = get_valid_int("Enter pyramid height: ", 9);

    // Generate and print our pyramid
    generate_pyramid(height);
}

// Get valid integer
int get_valid_int(string q, int max)
{
    int n;

    do
    {
        n = get_int("%s", q);
    }
    while (n < 1 || n >= max);

    return n;
}

// FUnction to generate and print pyramid
void generate_pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int k = height; k > i; k--)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}