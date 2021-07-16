#include <cs50.h>
#include <stdio.h>

int main(void) {
    char *s = get_string("s: ");
    char *j = get_string("j: ");

    if (*s == *j) {
        printf("Same\n");
    }
    else {
        printf("Different\n");
    }
}