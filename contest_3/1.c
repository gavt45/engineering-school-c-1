#include <stdlib.h>
#include <stdio.h>
// #include <malloc>

int main(){
    int n;
    scanf("%d", &n);
    int * a = (int*)malloc(sizeof(int) * n);
    // long long * b = (long long*)malloc(sizeof(long long) * 8);
    // int * b = (int*)calloc(1337, sizeof(int));
    // printf("%X\n", b-a);
    // for (long long i = 0; i < 1; i++)
    // {
    //     a[i] = i/12;
    // }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = i+1; j < n; j++){
            if (a[j] < a[i]) c++;
        }
        printf("%d ", c);
    }
    // printf("%lld", a[0]);

    // free(a);
    // free(b);
    return 0;
}