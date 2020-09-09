#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    if (a > b && b >= 0)
        printf("legal\n");
    else
        printf("out of bounds\n");
    return 0;
}
