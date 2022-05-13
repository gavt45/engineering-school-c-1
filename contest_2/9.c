#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// #define F(x,n) pow(-1, (n))*pow((x),2*(n)+1)/(2*(n)+1)
#define ABS(x) ((x)>=0.0?(x):(-(x)))

int main(){
    int k;
    double x = 0.0,eps=0.99999,y=0.0,mn;
    // int imin=-1;
    scanf("%lf %lf", &x, &eps);
    int i = 0;
    y=x;
    mn = x;
    while (ABS(mn/(2*i+1)) >= eps) {
        i++;
        mn *= -1*x*x;
        y+=mn/(2*i+1);   
    }
    printf("%.5f",y);
    return 0;
}
