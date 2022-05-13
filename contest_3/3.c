#include <stdlib.h>
#include <stdio.h>
// #include <malloc>

int main(){
    int n, t;
    scanf("%d", &n);
    int * a = (int*)malloc(10001 * sizeof(int));
    // int * t = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < 10001; i++)
    {
        a[i] = 0;
    }
    

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        a[t] += 1;
    }

    for (int i = 0; i < 10001; i++)
    {
        if (a[i] != 0) printf("%d: %d\n", i, a[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n", t[i]);
    // }
    
    
    
    // int * b = (int*)calloc(1 337, sizeof(int));

    // scanf("%d", &a[0]);

    // printf("%d", a[0]);

    // free(a);
    // free(b);
    return 0;
}