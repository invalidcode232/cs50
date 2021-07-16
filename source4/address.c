#include <stdio.h>

int main(void) {
    char *s = "HI!";
    //string *p = &s;

    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s - 100));

}