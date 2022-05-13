#include <stdlib.h>
#include <stdio.h>

int binsearch (int a [] , int _l , int _r , int t );
int binsearch (int a [] , int _l , int _r , int t ){
    /// l: number of elements
    int l = _l,m,x=-1;
    int r = _r;
    while (l <= r){
        m = (l + r) / 2;
        if (a[m] == t){
            x = m;
        }
        if (a[m] <= t)
            l = m+1;
        else
            r = m-1;
        // int x = l
    }
//    printf("found %d on %d", t, x);
//    if (x!=-1) while (a[x+1] == a[x]) x++;
    return x;
}


int main(){
    int n,k,x,last,last_x;
    scanf("%d", &n);

    int * a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    scanf("%d", &x);
    last_x = x;
    last = binsearch(a,0,n-1,x);
    printf("%d\n", last);
    for (int j = 1; j < k; ++j) {
        scanf("%d", &x);
        int r = last_x <= x? last : 0, l = last_x >= x ? last : n-1;
        last_x = x;
        x+=last;
        last = binsearch(a, 0, n-1, x);
        printf("%d\n", last);
    }
    return 0;
}