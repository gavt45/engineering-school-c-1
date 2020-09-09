#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define F(x,n) pow(-1, (n))*pow((x),2*(n)+1)/(2*(n)+1)

int main(){
    int k;
    double x = 0.0,eps=0.99999,y=0.0;
    // int imin=-1;
    scanf("%lf %lf", &x, &eps);
    int i = 0;
    y=F(x,0);
    while (fabs(F(x,i)) >= eps)
    {
        i++;
        y+=F(x,i);
    }
    printf("%.5f",y);
    return 0;
}