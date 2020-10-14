//
// Created by Gav on 07/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_n(char a){
    char * alph = "0123456789abcdef";
    return strchr(alph, a) - alph;
}

int main() {
//    freopen("input.txt", "r", stdin);
    int b;
    char n[30];
    int o = 0;
    scanf("%d", &b);
    scanf("%s", n);
//    printf("len: %d\n", (int)log10(n)+1);
    int len = strlen(n);
    int i = 0;
    while (i < len) {
//        printf("+ %d * %d ^ %d\n", get_n(n[len-i-1]), b, i);
        o += get_n(n[len-i-1]) * (int)pow(b, i);
//        n /= 10;
        i++;
    }
    printf("%d", o);
    return 0;
}
