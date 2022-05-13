//
// Created by Gav on 07/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *a, char *b) {
//    char * c = (char *)malloc((asz+bsz+1) * sizeof(char));
//    for (int i = 0; i < asz+bsz; ++i) {
//        c[i] = '\0';
//    }
//    printf("A: %s B: %s asz: %d bsz %d\n",a,b,asz,bsz);
//    strncpy(c, a, asz);
//    printf("After 1: %s\n", c);
//    strncpy(c+asz, b, bsz);
//    printf("After 2: %s\n", c);
    strcat(a, b);
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    char word[101];
    scanf("%d", &n);
//    char arr[4096];
//    strcpy(arr, "");
//    arr[0] = '\0';
    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < 100; ++j) {
//            word[i] = 0;
//        }
        scanf("%s", word);
//        if (word[0] == '\n')
//            continue;
//        tmp = arr;
//        int wlen = strlen(word);
//        concat(arr, word);
        printf("%s", word);
//        l += wlen;
//        printf("%d %s\n",l,  arr);
//        free(tmp);
    }
//    arr[l] = '\0';
//    printf("%s", arr);
}
