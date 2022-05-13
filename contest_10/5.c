//
// Created by Gav on 07/11/2020.
//
#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int n, int pivot) {
    int k = 0, p = 0, o = 0;
    int * t = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        if (a[i] < pivot) {
            t[k] = a[i];
            k++;
        } else if (a[i] == pivot){
            p++;
        }
    }
//    printf("K after first cycle: %d\n", k);
    o = k;
    for (int j = 0; j < p; ++j) {
        t[k+j] = pivot;
    }
    o += p/2;
//    printf("o: %d\n", o);
    k += p;
//    printf("k after addition of pivots: %d\n", k);
    for (int i = 0; i < n; ++i) {
        if (a[i] > pivot) {
            t[k] = a[i];
            k++;
        }
    }
//    printf("Array: ");
    for (int l = 0; l < n; ++l) {
//        printf("%X ", t[l]);
        a[l] = t[l];
    }
//    printf("\n");
//    a = t;
    return o;
}

int main(){
    FILE * fd = fopen("input.bin", "rb");
    FILE * fo = fopen("output.bin", "wb");

    int n,p;
    fread(&n, 4, 1, fd);
    fread(&p, 4, 1, fd);

    int * a = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        fread(&a[i], 4, 1, fd);
    }

    int k = partition(a, n, p);

    fwrite(&k, 4, 1, fo);

    for (int j = 0; j < n; ++j) {
        fwrite(&a[j], 4, 1, fo);
    }
    return 0;
}
