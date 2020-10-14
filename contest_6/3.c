//
// Created by Gav on 07/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((y)>(x)?(y):(x))

int main() {
    char a[100];
    char b[100];
    char c[100];
    for (int j = 0; j < 100; ++j) {
        c[j] = (char)(0x41+27);
    }
    char tmp;
    scanf("%s %s", a, b);
    int count = 0;
    for (int i = 0; i < strlen(a); ++i) {
        if (strchr(b, a[i]) < strlen(b)+1){
//            printf("%c", a[i]);
            c[count] = a[i];
            count++;
        }
    }

    if (count == 0){
        printf("Empty Set");
        return 0;
    }
//    printf("Count: %d\n", count);
//    int k = 0;
//    while ( k < strlen(b)){
//        printf("%d ", c[k]);
//        k++;
//    }
    for (int i = 0; i < count-1; i++) {
        for (int j = i+1; j < count; j++) {
            if (c[i] > c[j]) {
                tmp = c[i];
                c[i] = c[j];
                c[j] = tmp;
            }
        }
    }
    int k = 0;
    while (c[k] != 0x41+27 && k < strlen(b)){
        printf("%c", c[k]);
        k++;
    }

    return 0;
}
