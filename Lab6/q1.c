#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left, *right;
};

typedef struct node *NODE;
NODE root = NULL;

NODE insert(NODE node, int ele) {
    if (node == NULL) {
        node = (NODE)malloc(sizeof(struct node));
        node->val = ele;
        node->left = node->right = NULL;
        return node;
    }
    if (ele < node->val)
        node->left = insert(node->left, ele);
    else
        node->right = insert(node->right, ele);
    return node;
}

int countNodes(NODE node) {
    if (node == NULL)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int main() {
    int choice, ele;
    while (1) {
        printf("\n--- Lab 6 Q1: Count Nodes in Binary Tree ---\n");
        printf("1. Insert Element\n2. Display Total Node Count\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("Total Nodes: %d\n", countNodes(root));
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
