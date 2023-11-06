#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int balance_factor(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

struct Node* new_node(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rotate_left(struct Node* y) {
    struct Node* x = y->right;
    struct Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* rotate_right(struct Node* x) {
    struct Node* y = x->left;
    struct Node* T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node* insert_node(struct Node* root, int key) {
    if (root == NULL) return new_node(key);

    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } else {
        root->right = insert_node(root->right, key);
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = balance_factor(root);

    // Left heavy
    if (balance > 1) {
        if (key < root->left->key) {
            printf("Right Rotation on node with key %d\n", root->key);
            return rotate_right(root);
        } else {
            printf("Left-Right Rotation on node with key %d\n", root->key);
            root->left = rotate_left(root->left);
            return rotate_right(root);
        }
    }

    // Right heavy
    if (balance < -1) {
        if (key > root->right->key) {
            printf("Left Rotation on node with key %d\n", root->key);
            return rotate_left(root);
        } else {
            printf("Right-Left Rotation on node with key %d\n", root->key);
            root->right = rotate_right(root->right);
            return rotate_left(root);
        }
    }

    return root;
}

void print_balance_factors(struct Node* root) {
    if (root != NULL) {
        printf("Balance factor of node with key %d is %d\n", root->key, balance_factor(root));
        print_balance_factors(root->left);
        print_balance_factors(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int k = 6;
    int keys[] = {10, 20, 30, 40, 50, 25};
    
    int i;
    for ( i = 0; i < k; i++) {
        root = insert_node(root, keys[i]);
        printf("Inserted node with key %d\n", keys[i]);
        print_balance_factors(root);
        printf("-------------\n");
    }

    return 0;
}