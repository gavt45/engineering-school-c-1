#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int k;
    char f = 0;
    scanf("%d", &k);
    for (int j = 0; j <= (int)log10(k); j++){
        int d = (k/(int)pow(10,j))%10;
        if (d != 0 || f) {
            printf("%d", d);
            f = 1;
        }
    }
    return 0;
}