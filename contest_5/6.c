//
// Created by Gav on 02/10/2020.
//
#include <stdio.h>
#include <stdlib.h>

void next_permut ( int a [] , int n ){
    int p=n-1, t;

    for (int i = n-1; i > 0; --i) {
        if (a[i-1] < a[i]) {
            p = i-1;
            break;
        }
    }

    int ins = n-1;
    while (a[ins] < a[p]) {
        ins--;
    }
    if (ins == p){
        // latest
        for (int j = 0, k = n-1; j < k; j++,k--) {
            t = a[j];
            a[j] = a[k];
            a[k] = t;
        }
        return;
    }
    //swap
    t = a[p];
    a[p] = a[ins];
    a[ins] = t;
//    printf("ins: %d; p: %d\n", ins, p);
//    printf("before reverse:\n");
//    for (int i = 0; i < n; i++){
//        printf("%d ", a[i]);
//    }
    //reverse
    for (int j = p+1, k = n-1; j < k; j++,k--) {
        t = a[j];
        a[j] = a[k];
        a[k] = t;
    }
}

int main(){
    int n;
    char tmp = 'F';
    scanf("%d", &n);

    int * a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < 2*n; ++i) {
        scanf("%c", &tmp);
        if (i%2==1)
            a[i/2] = (int)(tmp);
    }

    next_permut(a, n);

    for (int j = 0; j < n; ++j) {
        printf("%c ", ((char)a[j]));
    }

    return 0;
}
