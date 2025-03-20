#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choosing the last element as pivot
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *opCount) {
    if (low < high) {
        (*opCount)++; // count the partition operation
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, opCount);
        quickSort(arr, pi + 1, high, opCount);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int opCount = 0;
    quickSort(arr, 0, n-1, &opCount);
    printf("Sorted Array: ");
    printArray(arr, n);
    printf("Operation Count (partition calls): %d\n", opCount);
    return 0;
}
