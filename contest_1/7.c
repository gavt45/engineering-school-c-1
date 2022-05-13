#include <stdio.h>

typedef long int li;

int main(){
    li h,m,s,k;
    scanf("%li %li %li %li", &h, &m, &s, &k);

    s += k + m * 60LL + h * 3600LL;

    s %= 24 * 60 * 60;

    printf("%li %li %li", (s/3600)%24, (s/60)%60, s%60);
    return 0;
}