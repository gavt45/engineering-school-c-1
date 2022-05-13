//
// Created by Gav on 07/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *a, int len) {
    char t = '\0';
    for (int i = 0; i < len / 2; ++i) {
        t = a[i];
//        printf("t: %c",t);
        a[i] = a[len - i - 1];
//        printf("a[%d]=%c",len - i - 1,a[len - i - 1]);
        a[len - i - 1] = t;
    }
//    printf("A after reverse: %s", a);
}


int main() {
    freopen("input.txt", "r", stdin);
    int b, n;
    char * alph = "0123456789abcdef";
    char str[21];
    scanf("%d%d", &b, &n);
    if (n == 0){
        printf("0");
        return 0;
    }
    while (n > 0){
        strncat(str, &alph[n%b], 1);
        n/=b;
    }
    reverse(str, strlen(str));
    printf("%s", str);

    return 0;
}