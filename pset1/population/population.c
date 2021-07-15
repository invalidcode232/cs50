#include <cs50.h>
#include <stdio.h>

int get_years_to_threshold(int start, int end);
int get_valid_int(string q, int min);

int main(void)
{
    // Prompt for start size
    int start = get_valid_int("Start size: ", 0);

    // Prompt for end size
    int end = get_valid_int("End size: ", start);

    // TODO: Calculate number of years until we reach threshold
    int years = get_years_to_threshold(start, end);

    // Print number of years
    printf("Years: %i\n", years);
}

// Get input with validation check
int get_valid_int(string q, int min)
{
    int n;

    do
    {
        n = get_int("%s", q);
    }
    while (n < 1 || n < min || n < 9);

    return n;
}

// Get years to threshold
int get_years_to_threshold(int start, int end)
{
    int n = start;
    int years = 0;

    // Loop until n is more than end
    while (n < end)
    {
        int born = (n / 3) - (n / 4);

        n += born;

        years++;
    }

    return years;
}