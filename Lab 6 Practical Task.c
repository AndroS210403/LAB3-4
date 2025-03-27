#include <stdio.h>
int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int selected;
    int i, j, found = 0;
    // Print original array
    printf("Original array:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    // Get selected element
    printf("Enter the element to select: ");
    scanf("%d", &selected);

    // Find the element's position
    found = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (arr[i][j] == selected) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }
       if (!found) {
        printf("Element not found in the array.\n");
        return 1;
    }
    // Swap elements in row and column
    int k = 1;
    while ((j + k) < 3 && (i + k) < 3) {
    // Swap arr[i][j + k] and arr[i + k][j]
        int temp = arr[i][j + k];
        arr[i][j + k] = arr[i + k][j];
        arr[i + k][j] = temp;
        k++;
    }
   // Print modified array
    printf("Modified array:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
     return 0;
}