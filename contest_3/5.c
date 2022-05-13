#include <stdlib.h>
#include <stdio.h>
// #include <malloc>

typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);
    int * resh = (int*)malloc(n * sizeof(int));
    // int * b = (int*)calloc(1337, sizeof(int));

    for (ll i = 0; i <= n; i++)
    {
        resh[i] = 1;
    }
    

    for (ll i = 2; i <= n; ++i) {
        if (resh[i] == 1)
            if (1LL*i*i <= n)
                for (ll j = i*i; j <= n; j+=i)
                    resh[j] = 0;
    }

    for (ll i = 2; i <= n; i++)
    {
        if (resh[i] == 1) printf("%lld ", i);
    }
    

    // printf("%d", a[0]);

    // free(a);
    // free(b);
    return 0;
}
