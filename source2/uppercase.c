#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string uppercase(string str);

int main(void) {
    string s = get_string("Before: ");

    printf("After: %s\n", uppercase(s));
}

string uppercase(string str) {
    for (int i = 0, len = strlen(str); i < len; i++) {
        str[i] = toupper(str[i]);
    }

    return str;
}