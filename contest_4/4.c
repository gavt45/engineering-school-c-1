#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void shake_sort (int a [] , int n );

void shake_sort (int a [] , int n ){
    char s = 1; // "swapped" flag
    int left = 0;
    int right = n-1;
    int t;
    while (s != 0) { // перетряхиваем 2 раза
        s=0;
        for (int i = left; i < right; ++i) {
            if (a[i] > a[i + 1]) {
                t = a[i];
                //^= a[i + 1] ^= a[i] ^= a[i + 1];
                a[i] = a[i+1];
                a[i+1] = t;
                s = 1;
            }
        }
        right--;
        if (s == 0)
            break;
        s = 0;
        for (int j = right; j >= left; j--) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                //^= a[i + 1] ^= a[i] ^= a[i + 1];
                a[j] = a[j+1];
                a[j+1] = t;
                s = 1;
            }
        }
        left++;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int * a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    shake_sort(a, n);

    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}