#include <stdio.h>
#include <math.h>

int main(){
    double xa,ya,xb,yb,xc,yc,a,b,c,p,s;
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
    a=sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    b=sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
    c=sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));

    p = (a+b+c)/2.0;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.3f\n%.3f", p*2.0, s);
    return 0;
}