//
// Created by Gav on 02/12/2020.
//
//
// Created by Gav on 02/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x>y)?(x):(y))

typedef struct Node_s {
    char * str;
    struct Node_s *left;
    struct Node_s *right;
} Node;

void insert_val(Node *node, char * v) {
    if (strcmp(node->str, v) > 0) {
        if (node->left == NULL) {
            Node *new_node = (Node *) malloc(sizeof(Node));
            new_node->str = (char*)malloc(sizeof(char)*(strlen(v)+1));
            strcpy(new_node->str, v);
            new_node->left = NULL;
            new_node->right = NULL;
            node->left = new_node;
            return;
        } else insert_val(node->left, v);
    }
    if (strcmp(node->str, v) == 0) return;
    if (strcmp(node->str, v) < 0) {
        if (node->right == NULL) {
            Node *new_node = (Node *) malloc(sizeof(Node));
            new_node->str = (char*)malloc(sizeof(char)*(strlen(v)+1));
            strcpy(new_node->str, v);
            new_node->left = NULL;
            new_node->right = NULL;
            node->right = new_node;
            return;
        } else insert_val(node->right, v);
    }
}

void inf(Node *node) {
    if (!node) return;
    inf(node->left);
    printf("%s\n", node->str);
    inf(node->right);
}

int main() {
    freopen("input.txt", "r", stdin);
    char tmp[256] = { 0 };
    Node *root = (Node *) malloc(sizeof(Node));
    scanf("%s", tmp);
    root->str = (char*)malloc(sizeof(char)*(strlen(tmp)+1));
    strcpy(root->str, tmp);
    root->left = NULL;
    root->right = NULL;
    while (scanf("%s", tmp) != EOF) {
        insert_val(root, tmp);
    }

    inf(root);

    return 0;
}
