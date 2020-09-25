#include <stdlib.h>
#include <stdio.h>

int invtab_to_permut ( int b [] , int a [] , int n );
int invtab_to_permut ( int b [] , int a [] , int n ){
    for (int i = 0; i < n; ++i) {
        int c = 0;
        int j = 0;
        while (c <= a[i]){
            if (j > n) return -1;
            if (b[j] == -1){
                c+=1;
            }
            j+=1;
        }
        b[j-1] = i+1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    int * a = (int *)malloc(n * sizeof(int));
    int * b = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = -1;
    }

    int res = invtab_to_permut(b, a, n);
//    printf("\n");
    if (res == -1) {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
    return 0;
}
