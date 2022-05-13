#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// #include <malloc>
#define MIN(x,y) (((x)<=(y))?(x):(y))

int main(){
    int n;
    double k;
    scanf("%d %lf", &n, &k);
    double * a = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &a[i]);
    }

    int l = 0,x=-1,m;
    double min = 10000001;
    int r = n-1;
    while (l <= r){
        m = (l + r) / 2;
        if (fabs(a[m]-k) < min){
            x = m;
            min = fabs(a[m]-k);
//            break;
        }
        if (a[m] <= k)
            l = m+1;
        else
            r = m-1;
        // int x = l
    }

    printf("%d",x);

    return 0;
}
