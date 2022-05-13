#include <stdlib.h>
#include <stdio.h>
// #include <malloc>

int main(){
    int n;
    scanf("%d", &n);
    int * a = (int*)malloc(n * sizeof(int));
    int * t = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        t[i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = k-1; i < n; i+=k)
        {
            t[k-1] += a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", t[i]);
    }
    
    
    
    // int * b = (int*)calloc(1 337, sizeof(int));

    // scanf("%d", &a[0]);

    // printf("%d", a[0]);

    // free(a);
    // free(b);
    return 0;
}