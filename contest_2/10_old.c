#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int k;
    scanf("%d", &k);
    int i = 1, n = 1, t;
    while (i <= k){
        t=i;
        while (i<=t+(int)log10(n)){
            if (i == k) {
                printf("%d", (n/(int)pow(10,((int)log10(n) - (i-t))))%10);
                return 0;
            }
            // printf("n: %d i: %d t: %d; DIGIT: %d\n", n, i, t, (n/(int)pow(10,((int)log10(n) - (i-t))))%10);
            i++;
        }
        n++;
    }
    return 0;
}