//
// Created by Gav on 02/10/2020.
//
#include <stdio.h>
#include <math.h>

typedef long long ll;

int main() {
    ll n, c = 0, k = 1;

    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        while (n / k - k - i >= 1) { // 1*z <= 10/y {y >= x;
            printf("k: %lld count: %lld\n", k, n / k - k - i);
            c += n / k - k - i;
            k++;
        }
    }

    printf("%lld", c);
    return 0;
}