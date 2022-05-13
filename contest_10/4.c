//
// Created by Gav on 07/11/2020.
//
#include <stdio.h>
#include <stdlib.h>

#define MIN(X,Y) (((X)>(Y))?(Y):(X))

int merge(const int *a, int ak, const int *b, int bk, int *res) {
    int i = 0;
    int j = 0;
    for (int k = 0; k < ak + bk; ++k) {
        if (a[i] < b[j]){
            if (i < ak && i != -1){
                res[k] = a[i];
                i++;
            }else {
                i = -1;
                if (j < bk && j != -1){
                    res[k] = b[j];
                    j++;
                }
            }
        }else {
            if (j < bk && j != -1){
                res[k] = b[j];
                j++;
            }else {
                j = -1;
                if (i < ak && i != -1){
                    res[k] = a[i];
                    i++;
                }
            }
        }
//        printf("res[%d] = %d\n", k, res[k]);
    }
    return 0;
}

int main(){
    FILE * fd = fopen("input.bin", "rb");
    FILE * fo = fopen("output.bin", "wb");

    int n, m;
    fread(&n, 4, 1, fd);
    fread(&m, 4, 1, fd);

//    printf("N: %d; M: %d\n", n, m);

    int * a = (int*)malloc(n * sizeof(int));
    int * b = (int*)malloc(m * sizeof(int));
    int * res = (int*)malloc((n + m) * sizeof(int));

    for (int i = 0; i < n; ++i) {
        fread(&a[i], 4, 1, fd);
    }

    for (int j = 0; j < m; ++j) {
        fread(&b[j], 4, 1, fd);
    }

    merge(a,n,b,m,res);

    for (int k = 0; k < n + m; ++k) {
        fwrite(&res[k], 4, 1, fo);
    }
    return 0;
}
