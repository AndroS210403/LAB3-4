#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    
    memcpy(L, a + l, n1 * sizeof(int));
    memcpy(R, a + m + 1, n2 * sizeof(int));
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = L[i] <= R[j] ? L[i++] : R[j++];
    
    memcpy(a + k, L + i, (n1 - i) * sizeof(int));
    memcpy(a + k, R + j, (n2 - j) * sizeof(int));
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void printArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main() {
    int n;
     // Get valid array size (1-10)
    do {
        printf("Enter number of elements (1-10): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = -1;
        }
    } while(n < 1 || n > 10);  // Changed range check
    
    int *arr = malloc(n * sizeof(int));
    
    // Get array elements with validation
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        while(1) {
            printf("Element %d: ", i+1);
            if (scanf("%d", &arr[i]) == 1) {
                break;
            }
            while (getchar() != '\n');
            printf("Invalid input. Please enter an integer.\n");
        }
    }
    printf("\nOriginal array:\n");
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printf("\nSorted array:\n");
    printArray(arr, n);
    free(arr);
    return 0;
}