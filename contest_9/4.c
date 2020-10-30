//
// Created by Gav on 28/10/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fd = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout);
    int cnt[127] = { 0 };
    int chr;

    while (1) {
        chr = fgetc(fd);
        if (chr == EOF) break;
        cnt[chr]++;
    }

    for (int j = 32; j < 127; ++j) {
        if (cnt[j] > 0) {
            printf("%c ", j);
            for (int i = 0; i < cnt[j]; ++i) {
                printf("#");
            }
            printf("\n");
        }
    }

    fclose(fd);
    return 0;
}

