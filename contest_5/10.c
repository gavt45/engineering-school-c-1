//
// Created by Gav on 02/10/2020.
//
#include <stdio.h>
#include <math.h>

typedef long long ll;

int main() {
    ll n, sum = 0, k = 1;

    scanf("%lld", &n);
    // https://www.desmos.com/calculator/xsmmuiktol
    for (ll x = 1; x <= cbrtl(n); ++x) {
        ll y = x;
        while (n/(x*y)-y+1>0){
//            printf("For x=%lld y=%lld z_count=%lld\n", x, y, n/(x*y)-y+1);
            sum += n/(x*y)-y+1;
            y++;
        }
    }

    printf("%lld", sum);
    return 0;
}