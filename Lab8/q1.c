#include <stdio.h>
#include <stdlib.h>

void siftUp(int arr[], int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(arr[i] > arr[parent]) {
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

void insertHeap(int arr[], int *n, int key) {
    arr[(*n)++] = key;
    siftUp(arr, *n - 1);
}

void printHeap(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n = 0;
    int keys[] = {4, 10, 3, 5, 1, 7, 8};
    int kSize = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < kSize; i++) {
        insertHeap(arr, &n, keys[i]);
    }
    printf("Heap (Top-Down): ");
    printHeap(arr, n);
    return 0;
}
