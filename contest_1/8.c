#include <stdio.h>
#include <math.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
// typedef long double ;

int main(){
    double a,b,c,d,x1,x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    d = b * b - 4 * a * c;
    if (d < 0){
        printf("NO");
        // return 0;
    } else if (a == 0 && b == 0 && c == 0){
        printf("MANY");
    } else if (a == 0 && b == 0 && c != 0){
        printf("ERROR");
    } else if (a == 0 && b != 0 && c != 0) {
        printf("1\n%.5f",(-c)/b);
    } else if (d == 0) {
        x1 = (-b)/(2.0 * a);
        printf("1\n%.5f", x1);
    } else if (d > 0) {
        x1 = (-b+sqrt(d))/(2.0 * a);
        x2 = (-b-sqrt(d))/(2.0 * a);
        printf("2\n%.5f %.5f", MIN(x1, x2), MAX(x1, x2));
    }
    return 0;
}
