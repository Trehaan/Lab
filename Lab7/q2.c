#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

typedef struct Node* NODE;

int height(NODE n) {
    return n ? n->height : 0;
}

NODE newNode(int key) {
    NODE node = (NODE)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

NODE rotateRight(NODE y) {
    NODE x = y->left;
    NODE T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    return x;
}

NODE rotateLeft(NODE x) {
    NODE y = x->right;
    NODE T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    return y;
}

int getBalance(NODE n) {
    return n ? height(n->left) - height(n->right) : 0;
}

NODE insertAVL(NODE node, int key) {
    if (!node)
        return newNode(key);
    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else if (key > node->key)
        node->right = insertAVL(node->right, key);
    else
        return node;
    
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void findSuccessorPredecessor(NODE root, int key, NODE *succ, NODE *pred) {
    *succ = *pred = NULL;
    NODE current = root;
    while(current) {
        if(current->key == key) {
            if(current->left) {
                NODE temp = current->left;
                while(temp->right)
                    temp = temp->right;
                *pred = temp;
            }
            if(current->right) {
                NODE temp = current->right;
                while(temp->left)
                    temp = temp->left;
                *succ = temp;
            }
            break;
        }
        else if(key < current->key) {
            *succ = current;
            current = current->left;
        } else {
            *pred = current;
            current = current->right;
        }
    }
}

int main() {
    NODE root = NULL;
    int keys[] = {30, 20, 40, 10, 25, 35, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < n; i++)
        root = insertAVL(root, keys[i]);
    
    int query;
    printf("Enter key to find its successor and predecessor: ");
    scanf("%d", &query);
    NODE succ, pred;
    findSuccessorPredecessor(root, query, &succ, &pred);
    if(pred)
        printf("Predecessor of %d is %d\n", query, pred->key);
    else
        printf("No Predecessor for %d\n", query);
    if(succ)
        printf("Successor of %d is %d\n", query, succ->key);
    else
        printf("No Successor for %d\n", query);
    return 0;
}
