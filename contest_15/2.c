//
// Created by Gav on 09/12/2020.
//
#include <stdlib.h>
#include <stdio.h>

int partition(int *a, int start, int stop) {
    int x=a[start],i=start-1,j=stop+1,tmp;
    while (1) {
        do  j--; while (a[j] > x);
        do  i++; while (a[i] < x);
        if  (i < j) {
//            swap(&a[i], &a[j]);
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

void sort(int *a, int start, int stop) {
    if (start < stop) {
        int p = partition(a, start, stop);
        sort(a, start, p);
        sort(a, p + 1, stop);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int * a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    s0rt(a, n);
    for (int j = 0; j < n; ++j) {
        printf("%d ", a[j]);
    }
    return 0;
}
