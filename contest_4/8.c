#include <stdlib.h>
#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm (ll a, ll b) { // a*b/gcd(a,b)
    return a * b / gcd (a, b);
}

int main(){
    int n;
    ll a,b;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", lcm(a, b));
    }
    return 0;
}