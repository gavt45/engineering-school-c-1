#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int k;
    scanf("%d", &k);
    int i = 1, n = 1, t;

    //start: n: 100 num of digits for now: 189 t: 188
    //start: n: 1000 num of digits for now: 2889 t: 2887
    int power10 = 1;
    while (i+9*power10*(int)pow(10,power10-1) < k){
        i+=9*power10*(int)pow(10,power10-1);
        n=pow(10,power10);
        t=i-2;
        power10 += 1;
    }
    while (i <= k){
        // printf("start: n: %d num of digits for now: %d t: %d\n", n, i-1, t);
        t=i;
        if (i+(int)log10(n)+1 >= k){
            // printf("Before while: n: %d i: %d t: %d\n", n, i, t);
            while (i<=t+(int)log10(n)){
                // printf("n: %d i: %d t: %d; DIGIT: %d\n", n, i, t, (n/(int)pow(10,((int)log10(n) - (i-t))))%10);
                if (i == k) {
                    printf("%d", (n/(int)pow(10,((int)log10(n) - (i-t))))%10);
                    return 0;
                }
                i++;
            }
        } else {
            // printf("n: %d i: %d t: %d\n", n, i, t);//, (n/(int)pow(10,((int)log10(n)+1 - (i-t))))%10);
            i+=(int)log10(n)+1;
            // printf("n: %d num of digits for now: %d t: %d\n", n, i-1, t);
        }
        n++;
    }
    return 0;
}