#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TABLE_SIZE 10

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int table[], int key) {
    int index = hash(key);
    while(table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index] = key;
}

bool search(int table[], int key, int *compCount) {
    int index = hash(key);
    int start = index;
    while(table[index] != -1) {
        (*compCount)++;
        if(table[index] == key)
            return true;
        index = (index + 1) % TABLE_SIZE;
        if(index == start)
            break;
    }
    return false;
}

int main() {
    int table[TABLE_SIZE];
    for(int i = 0; i < TABLE_SIZE; i++)
        table[i] = -1;
    int keys[] = {23, 43, 1, 17, 8, 9};
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < n; i++)
        insert(table, keys[i]);
    printf("Open Addressing Hash Table: ");
    for(int i = 0; i < TABLE_SIZE; i++)
        printf("%d ", table[i]);
    printf("\n");
    int compCount = 0, keyToSearch = 17;
    if(search(table, keyToSearch, &compCount))
        printf("Key %d found with %d comparisons\n", keyToSearch, compCount);
    else
        printf("Key %d not found (comparisons: %d)\n", keyToSearch, compCount);
    return 0;
}
