//
// Created by Gav on 09/12/2020.
//
#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int n,_n;
    long long sum = 0;
    scanf("%d", &n);
    int * a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    s0rt(a, n);
    _n=n;
    if (n == 1) {
        printf("%d", a[0]);
        return 0;
    }
    for (int j = 0; j < n; ++j) {
        sum += (long long)a[j] * (n - j - 1);
    }
    printf("%lld", sum);
    return 0;
}
