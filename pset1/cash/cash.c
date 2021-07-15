#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float change;
    do
    {
        // Ask user for change
        change = get_float("How much change is owned: ");
    }
    while (change < 0);


    int convertCents = round(change * 100); //convert dollars to cents
    int coins = 0;

    while (convertCents >= 25) //loop for quaters
    {
        convertCents = convertCents - 25;
        coins++;
    }
    while (convertCents >= 10) //loop for dimes
    {
        convertCents = convertCents - 10;
        coins++;
    }
    while (convertCents >= 5) //loop for nicles
    {
        convertCents = convertCents - 5;
        coins++;
    }
    while (convertCents >= 1 && convertCents > 0) //loop for pennies
    {
        convertCents = convertCents - 1;
        coins++;
    }

    printf("%d\n", coins); //print the coins

}