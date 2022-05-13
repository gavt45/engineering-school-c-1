#include <stdio.h>
#include <stdlib.h>

typedef struct Element_s {
    int val;
    struct Element_s *next;
} Element;

int main(){
    freopen("input.txt", "r", stdin);

    Element start = {-1, NULL};
    Element *now = &start;

    int val;
    while (scanf("%d", &val) != EOF){
//        printf("val: %d\n", val);
        Element *new = (Element*)malloc(sizeof(Element));
        new->val = val;
        new->next = NULL;
        now->next = new;
        now = new;
    }

    now = start.next;
    Element *prev = NULL;

    while (now != NULL){
        if (prev != NULL){
            if (prev->val == now->val){
                prev->next = now->next;
                now = now->next;
                continue;
            }
        }
        prev = now;
        now = now->next;
    }

    now = start.next;

    while (now != NULL){
        printf("%d ", now->val);
        now = now->next;
    }

    return 0;
}
