#include <stdio.h>
#include <string.h>

#define SIZE 10

char parking[SIZE][20];

int hash(char key[]) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        strcpy(parking[i], "EMPTY");
    }
}

void parkVehicle(char vehicle[]) {
    int index = hash(vehicle);
    int start = index;

    while (strcmp(parking[index], "EMPTY") != 0) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Parking Full!\n");
            return;
        }
    }

    strcpy(parking[index], vehicle);
    printf("Vehicle parked at spot %d\n", index);
}

void display() {
    printf("\nParking table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Spot %d : %s\n", i, parking[i]);
    }
}

int main() {
    char vehicle[20];

    initialize();

    printf("Enter vehicle registration number : ");
    scanf("%s", vehicle);

    parkVehicle(vehicle);

    display();

    return 0;
}
