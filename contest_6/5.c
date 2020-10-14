//
// Created by Gav on 07/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    int n;
    char a[100];
    char word[100];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", word);
        reverse(word, strlen(word));
        printf("%s\n", word);
    }

}