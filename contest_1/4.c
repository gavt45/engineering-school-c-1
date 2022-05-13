#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    if (a/(float)b >= 0)
        printf("%d %d %d %d", a/b, ((a % b != 0) ? a/b+1 : a/b), a/b, a-b*(a/b));
    else
        printf("%d %d %d %d", ((a % b != 0) ? a/b-1 : a/b), a/b, a/b, a-b*((a % b != 0) ? a/b-1 : a/b));
    return 0;
}