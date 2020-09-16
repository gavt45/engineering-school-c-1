#include <stdlib.h>
#include <stdio.h>
// #include <malloc>

typedef long long ll;

int main(){
    int n, t;
    scanf("%d", &n);
    int * a = (int*)malloc(n * sizeof(int));
    // int * t = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        // a[t+1000] += 1;
    }
    ll max_sum = -5000*10000;
    int l_m=n+1,r_m=n+1;
    for (int l = 0; l < n; l++)
    {
        for (int r = n-1; r >= l; r--)
        {
            ll some_sum = 0;
            for (int i = l; i <= r; i++)
            {
                some_sum += a[i];
            }
            if (some_sum > max_sum){
                max_sum = some_sum;
                l_m = l;
                r_m = r;
            }else if (some_sum == max_sum && l < l_m){
                l_m = l;
                r_m = r;
            }else if (some_sum == max_sum && l == l_m && r < r_m){
                l_m = l;
                r_m = r;
            }
            // printf("l: %d, r: %d, sum: %lld\n", l, r, some_sum);
        }
        
    }

    // for (int i = 0; i < n; i++)
    // {
    printf("%d %d %lld", l_m, r_m, max_sum);
    // }
    
    
    
    // int * b = (int*)calloc(1 337, sizeof(int));

    // scanf("%d", &a[0]);

    // printf("%d", a[0]);

    // free(a);
    // free(b);
    return 0;
}