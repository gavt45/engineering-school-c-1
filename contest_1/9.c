#include <stdio.h>
#include <math.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
// typedef long double ;

int main(){
    int n,m,p,k,l,x,ost;
    scanf("%d\n%d %d %d %d", &n, &m, &p, &k, &l);
    x = (m)/(l*(p-1)+(k-1));
    p = (n)/(l*x)+((n%(l*x))!=0 ? 1 : 0);
    // printf("p: %d; n: %d; x: %d\n", p-1, n, x);
    ost = ((n - l*x*(p-1))%(x) != 0 ? 1 : 0);
    k = ((n - l*x*(p-1))/(x)) + ost;
    printf("%d %d", p, k);
    // printf("%lf",x);
    return 0;
}