#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[]) {
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            printf("%s", argv[i]);
        }
        printf("\n");
        //printf("Hello, %s\n", argv[1]);
    }
    else {
        printf("Hello, world\n");
    }
}