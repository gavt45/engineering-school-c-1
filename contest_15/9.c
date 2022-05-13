//
// Created by Gav on 10/12/2020.
//
#include <stdio.h>
#include <stdlib.h>

#define REENDIAN(X) (((X)>>24)&0xff) | (((X)<<8)&0xff0000) | (((X)>>8)&0xff00) | (((X)<<24)&0xff000000)

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
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        } else
            return j;
    }
}

void qsorj(int *a, int start, int stop) {
    if (start < stop) {
        int p = partition(a, start, stop);
        qsorj(a, start, p);
        qsorj(a, p + 1, stop);
    }
}

int main(){
    FILE * fd = fopen("input.bin", "r");
    FILE * fo = fopen("output.bin", "w");
    int n;
    fread(&n, sizeof(int), 1, fd);
//    n=REENDIAN(n);
//    printf("N: %d", n);
    int * arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        fread(&arr[i], sizeof(int), 1, fd);
//        arr[i] = REENDIAN(arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    for (int j = 0; j < n; ++j) {
//        arr[j] = REENDIAN(arr[j]);
        fwrite(&arr[j], sizeof(int), 1, fo);
    }
    fclose(fd);
    fclose(fo);
    return 0;
}
