#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct Pair {
    int a;
    int b;
};

char is_2(int * a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1)
            return FALSE;
    }
    return TRUE;
}

char is_3(int * a, int n, int m) {
    int * b = (int *)malloc(n * sizeof(int));

    for (int j = 0; j < n; ++j) {
        b[j] = -1;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) continue;
        if (b[a[i]-1] != -1){
            return FALSE;
        }
        b[a[i]-1] = i+1;
    }

    return TRUE;
}

char is_4(int * a, int n, int m) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) return FALSE;
    }
    return TRUE;
}


int main() {
    int n, m, t, t1;
    scanf("%d %d", &n, &m);

//    struct Pair **a = (struct Pair **) malloc(m * sizeof(struct Pair *));

    int * a = (int *)malloc(n * sizeof(int));
    int * b = (int *)malloc(n * sizeof(int));

    for (int j = 0; j < n; ++j) {
        a[j] = -1;
        b[j] = -1;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &t, &t1);
//        printf("a[%d] was %d", t, a[t-1]);
        if (a[t-1] != -1){
            printf("0");
            return 0;
        }
        a[t-1] = t1;
        b[t1-1] = t;
    }
    printf("1 ");
    if (is_2(a,n,m))
        printf("2 ");
    char inj = is_3(a,n,m);
    if (inj)
        printf("3 ");
    char sur = is_4(b,n,m);
    if (sur)
        printf("4 ");
    if (inj & sur)
        printf("5 ");


    return 0;
}
