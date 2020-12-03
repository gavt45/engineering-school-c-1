#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
    int val;
    struct Node_s * left;
    struct Node_s * right;
} Node;

void insert_val(Node * node, int v){
    if (v < node->val) {
        if (node->left == NULL){
            Node * new_node = (Node *)malloc(sizeof(Node));
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
            Node * new_node = (Node *)malloc(sizeof(Node));
            new_node->val = v;
            new_node->left = NULL;
            new_node->right = NULL;
            node->right = new_node;
            return;
        } else insert_val(node->right, v);
    }
}

void pref (Node *t)
{
    if (!t) return;
    printf("%d ", t->val);
    pref(t->left);
    pref(t->right);
}

void postf (Node *t)
{
    if (!t) return;
    postf(t->left);
    postf(t->right);
    printf("%d ", t->val);
}



int main(){
    freopen("input.txt", "r", stdin);
    int tmp;
    Node * root = (Node*)malloc(sizeof(Node));
    scanf("%d", &root->val);
    root->left = NULL;
    root->right = NULL;
    while (scanf("%d", &tmp) != EOF){
        insert_val(root, tmp);
    }

    pref(root);
    printf("\n");
    postf(root);
    return 0;
}