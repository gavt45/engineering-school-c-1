//
// Created by Gav on 25/11/2020.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Element_s {
    int val;
    struct Element_s *next;
} Element;

int main() {
    freopen("input.txt", "r", stdin);

    Element *now = NULL;

    int val, bad;
    scanf("%d", &bad);

    while (scanf("%d", &val) != EOF) {
//        printf("val: %d\n", val);
        Element *new = (Element *) malloc(sizeof(Element));
        new->val = val;
        new->next = now;
        now = new;
    }

//    Element *start = now;

    while (now != NULL) {
        if (now->next != NULL && now->next->val != bad) {
            printf("%d ", now->val);
        } else if (now->next == NULL) printf("%d ", now->val);
        now = now->next;
    }
    return 0;
}

