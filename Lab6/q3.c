#include <stdio.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, inv_count = 0;
    while(i <= mid - 1 && j <= right) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }
    while(i <= mid - 1)
        temp[k++] = arr[i++];
    while(j <= right)
        temp[k++] = arr[j++];
    for(i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if(right > left) {
        mid = (left + right) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid+1, right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    int inv_count = mergeSort(arr, temp, 0, n-1);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal Inversions: %d\n", inv_count);
    return 0;
}
