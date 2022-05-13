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
    sort(a, 0, n-1);
    for (int j = 0; j < n; ++j) {
        printf("%d ", a[j]);
    }
    return 0;
}