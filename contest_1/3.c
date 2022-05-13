#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main(){
    int a,b,c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    printf("%d", MIN(a,MIN(b,c)));
    return 0;
}