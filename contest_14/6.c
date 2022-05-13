//
// Created by Gav on 02/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x>y)?(x):(y))

typedef struct Node_s {
    char sign;
    int v;
    struct Node_s *left;
    struct Node_s *right;
} Node;

char is_char(char _char){
    if (_char == '+' || _char == '-' || _char == '*' || _char == '/') return 1;
    return 0;
}

Node * read_new_node(){
    char tmp;
    scanf("%c", &tmp);
    Node * new_node = (Node *)malloc(sizeof(Node));
    if (is_char(tmp)) {
        new_node->sign = tmp;
        new_node->v = 0;
    } else {
        new_node->v = tmp;
        new_node->sign = 0;
    }
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void build(Node * node) {

}

int calc(Node * node) {

}

int main(){
    freopen("input.txt", "r", stdin);
    char tmp;
    Node *root = (Node *) malloc(sizeof(Node));
    scanf("%c", &tmp);
    if (is_char(tmp)) {
        root->sign = tmp;
        root->v = 0;
    } else {
        root->v = tmp;
        root->sign = 0;
    }
    root->left = NULL;
    root->right = NULL;

    build(root);

    printf("asd\n");
    return 0;
}
