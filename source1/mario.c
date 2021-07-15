#include <cs50.h>
#include <stdio.h>

void print_block(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("*");
        }

        printf("\n");
    }
}

int main(void) {
    print_block(5, 5);
}