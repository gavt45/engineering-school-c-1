//
// Created by Gav on 09/12/2020.
//
//
// Created by Gav on 09/12/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int some_cnt=0, n;

int compare(const void * x1, const void * x2) {
    return ( *(int*)x1 - *(int*)x2 );
}


int partition(int *a, int start, int stop) {
    int x=a[start],i=start-1,j=stop+1,tmp;
    while (1) {
        do  j--; while (a[j] > x);
        do  i++; while (a[i] < x);
        if  (i < j) {
//            swap(&a[i], &a[j]);
            if (a[i] == a[j]) some_cnt++;
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        } else
            return j;
    }
}

void s0rt(int *array, int sz) {
    int s, i, j, tmp;
    for (s = sz / 2; s > 0; s /= 2) {
        for (i = s; i < sz; i++) {
            for (j = i - s; j >= 0; j -= s) {
                if (array[j] <= array[j + s]) break;
                tmp = array[j];
                array[j] = array[j + s];
                array[j + s] = tmp;
            }
        }
    }
}

void sort(int a[], int start, int stop) {
    if (start < stop) {
        int p = partition(a, start, stop);
//        for (int i = 0; i < n; ++i) {
//            if (i == p)
//                printf("/%d\\ ", a[i]);
//            else
//                printf("%d ", a[i]);
//        }
//        printf("\n");
        sort(a, start, p);
        sort(a, p + 1, stop);
    }
}

int main() {
    int c=1;
    scanf("%d", &n);
//    int * a = (int*)malloc(n * sizeof(int));
    int a[300000];//* a = (int*)malloc(n * sizeof(int));
    int * b = (int*)malloc(n * sizeof(int));
//    memset(b, 0, n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    s0rt(a, n);

    for (int j = 1; j < n; ++j) {
        if (a[j-1] != a[j]) {
            b[c-1] = a[j];
            c++;
        }
    }

    printf("%d\n%d\n", c, a[0]);

    for (int j = 0; j < c-1; ++j) {
//        if (a[j-1] != a[j])
        printf("%d\n", b[j]);
    }
    return 0;
}

