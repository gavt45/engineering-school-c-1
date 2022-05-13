#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > 0 && b > 0 && c > 0){
        printf("%d", 2*(a*b + a*c + b*c));
    }else{
        if (a<=0)
            printf("-1");
        else if (b<=0)
            printf("-2");
        else if (c<=0)
            printf("-3");
    }
    return 0;
}