#include <stdlib.h>
#include <stdio.h>
// #include <malloc>
#define MIN(x,y) (((x)<=(y))?(x):(y))
typedef long long ll;

struct element
{
    int val;
    struct element * next;
};


int main(){
    int n=0, k=0, t=0;
    scanf("%d %d", &n, &k);
    k%=n;
    k = (n-k)%n;
    struct element * start = (struct element *)malloc(sizeof(struct element));
    start->val = 0;
    start->next = NULL;
    // struct element end = {0, NULL};

    struct element * prev = start;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        struct element * el = (struct element *)malloc(sizeof(struct element));
        el->val = t;
        el->next = NULL;
        prev->next = el;
        prev = el;
    }
    struct element * tmp = NULL;
    struct element * prev_first = NULL;
    if (k > 0){
        int i = 0;
        tmp = start->next;
        while (i<k-1){
            tmp = tmp->next;
            i++;
        }
//        printf("%d: %d", i, tmp->val);
        prev_first = start->next;
        start->next = tmp->next;
        tmp->next = NULL;
        tmp = start->next;

        while (tmp->next != NULL){
            tmp = tmp->next;
        }
//        printf("");
        tmp->next = prev_first;
//        printf("");
    }
    tmp = start->next;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    return 0;
}
