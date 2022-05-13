#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void permut_to_invtab (int a [] , int b [] , int n );

void permut_to_invtab (int a [] , int b [] , int n ){
    for (int i = 1; i <= n; ++i)
        for (int j = 1; a[j-1] != i; ++j)
            if (a[j-1] > i)
                b[i-1]++;

}

int main() {
    int n;
    scanf("%d", &n);
    int * a = (int *)malloc(n * sizeof(int));
    int * b = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = 0;
    }

    permut_to_invtab(a, b, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", b[i]);
    }
    return 0;
}