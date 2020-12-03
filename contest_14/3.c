//
// Created by Gav on 02/12/2020.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x>y)?(x):(y))

typedef struct Node_s {
    int val;
    struct Node_s *left;
    struct Node_s *right;
} Node;

void insert_val(Node *node, int v) {
    if (v < node->val) {
        if (node->left == NULL) {
            Node *new_node = (Node *) malloc(sizeof(Node));
            new_node->val = v;
            new_node->left = NULL;
            new_node->right = NULL;
            node->left = new_node;
            return;
        } else insert_val(node->left, v);
    }
    if (v == node->val) return;
    if (v > node->val) {
        if (node->right == NULL) {
            Node *new_node = (Node *) malloc(sizeof(Node));
            new_node->val = v;
            new_node->left = NULL;
            new_node->right = NULL;
            node->right = new_node;
            return;
        } else insert_val(node->right, v);
    }
}

int deep_dark_fs(Node *node) {
    if (!node) return 0;
    if (node->left == NULL && node->right == NULL) return 1;
    return deep_dark_fs(node->left) + deep_dark_fs(node->right);
}

int main() {
    freopen("input.txt", "r", stdin);
    int tmp;
    Node *root = (Node *) malloc(sizeof(Node));
    scanf("%d", &root->val);
    root->left = NULL;
    root->right = NULL;
    while (scanf("%d", &tmp) != EOF) {
        insert_val(root, tmp);
    }

    printf("%d", deep_dark_fs(root));

    return 0;
}