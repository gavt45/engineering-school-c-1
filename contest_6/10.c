//
// Created by Gav on 14/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double a, res = 0;
    int b, z;
    scanf("%d", &b, &a);



    z = (int)a;
    a-=z;
//    printf("A after -: %lf\n", a);
    int i = 1;
    while (z > 0){
        res += (z%10)*i;
        z/=10;
        i*=b;
    }

    double j = 1.0/b;
    while (a > 0){
//        printf("a: %.30lf j: %.30lf; dig: %d\n", a, j, (int)round(a*10)%10);
        res += j * (double)(((int)round(a*10))%10);
        a*=10;
//        printf("%.30lf %d %.30lf\n",a,(int)round(a),trunc(a));
        a-=round(a);
//        printf("%lf\n",a);
        j*=1.0/b;
    }

    printf("%.5lf", res);

    return 0;
}
