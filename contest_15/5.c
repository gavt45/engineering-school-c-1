//
// Created by Gav on 09/12/2020.
//
#include <stdlib.h>
#include <stdio.h>

int compare(const void * x1, const void * x2) {
    return ( *(int*)x1 - *(int*)x2 );
}

int binsearch(int a[], int _l, int _r, int t) {
    /// l: number of elements
    int l = _l, m, x = -1;
    int r = _r;
    while (l <= r) {
        m = (l + r) / 2;
        if (a[m] == t) {
            x = m;
            break;
        }
        if (a[m] < t)
            l = m + 1;
        else
            r = m - 1;
        // int x = l
    }
//    printf("found %d on %d\n", t, x);
//    if (x!=-1) while (a[x+1] == a[x]) x++;
    return x;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int * a = (int*)malloc(n * sizeof(int));
    int * c = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    scanf("%d", &m);
    int * b = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    qsort(b, m, sizeof(int), compare);

    int cnt = 0;
    for (int j = 0; j < n; ++j) {
        if ((binsearch(b, 0, m-1, a[j]) == -1) && (cnt == 0 || c[cnt-1] != a[j])){
            c[cnt] = a[j];
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for (int k = 0; k < cnt; ++k) {
        printf("%d ", c[k]);
    }
}
