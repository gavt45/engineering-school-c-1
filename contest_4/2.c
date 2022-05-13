#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void ins_sort (int a [] , int n );

void ins_sort(int a [], int n){
    for (int i = 1; i < n; ++i) {
        int k = a[i];
        for (int j = i; j >= 0; j--) {
//            printf("k: %d; a[%d]: %d; i: %d\n", k, j, a[j], i);
            if (a[j-1] <= k || j == 0) {
                a[j] = k;
//                for (int i = 0; i < n; ++i) {
//                    printf("%d ", a[i]);
//                }
//                printf("\n");
                break;
            }
            else a[j] = a[j-1];
//            for (int i = 0; i < n; ++i) {
//                printf("%d ", a[i]);
//            }
//            printf("\n");
        }
//        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int * a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    ins_sort(a, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
