#include <stdio.h>
#include <math.h>

int main(){
    int n;
    double d;
    scanf("%d", &n);
    d = sqrt(8.0*n-7);
    d -= (int)d;
    if (d > 0)
        printf("0");
    else
        printf("1");
    return 0;
}