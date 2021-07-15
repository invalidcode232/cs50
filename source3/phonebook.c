#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    string name;
    string phone;
}
person;

int main(void) {
    person people[2];

    people[0].name = "James";
    people[0].phone = "+62-811-1249-018";

    people[1].name = "Juliana";
    people[1].phone = "+62-812-9009-018";

    for (int i = 0; i < 2; i++) {
        if (strcmp(people[i].name, "James")) {
            printf("Phone: %s\n", people[i].phone);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
