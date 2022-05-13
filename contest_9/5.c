//
// Created by Gav on 28/10/2020.
//
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main(){
    FILE *fd = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout);

    int arr[100001] = { 0 };

    int c;
    int i = 0;

    while (fscanf(fd, "%d", &c)>0){
        arr[i] = c;
        i++;
    }

    qsort(arr, i, sizeof(int), cmpfunc);

    int diff = arr[1]-arr[0];

    for (int j = 2; j < i; ++j) {
//        printf("diff: %d\n", arr[j]-arr[j-1]);
        if (arr[j]-arr[j-1] != diff){
            printf("NO");
            return 0;
        }
    }
    printf("%d", diff);
    return 0;
}