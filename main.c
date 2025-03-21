#include "Labs.h"
#include <stdio.h>
int main() {
    int choice;
    while (1) {
        printf("Enter 1 for lab1, 2 for lab2, 0 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                lab1();
                break;
            case 2:  // New option for lab2
                lab2();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}