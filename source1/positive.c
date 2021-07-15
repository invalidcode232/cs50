#include <cs50.h>
#include <stdio.h>

int get_positive_integer(void);

int main(void) {
    int i = get_positive_integer();

    printf("%i\n", i);
}

int get_positive_integer(void) {
    int n;

    do {
        n = get_int("Enter a number: ");
    } while (n < 1);

    return n;
}