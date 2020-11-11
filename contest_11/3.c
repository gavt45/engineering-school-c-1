//
// Created by Gav on 11/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StrChar_s{
    int oLowerCnt;
    int oUpperCnt;
    int oDigitsCnt;
} StrChar;

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt){
    int i = 0, ncnt = 0;
    while (iStr[i] != '\0'){
        if (iStr[i] >= '0' && iStr[i] <= '9') (*oDigitsCnt)++;
        if (iStr[i] >= 'A' && iStr[i] <= 'Z') (*oUpperCnt)++;
        if (iStr[i] >= 'a' && iStr[i] <= 'z') (*oLowerCnt)++;
        if (iStr[i] == '\n') ncnt++;
        i++;
    }
    return i - ncnt;
}

char str[128] = { 0 };

int main(){
    FILE * fd = fopen("input.txt", "r");
    StrChar characteristic;
    int ln = 1;
    while (fgets(str, 128, fd)){
        memset(&characteristic, 0, sizeof(characteristic));
        int cnt = calcLetters(str, &characteristic.oLowerCnt, &characteristic.oUpperCnt, &characteristic.oDigitsCnt);
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",
                ln, cnt, characteristic.oLowerCnt+characteristic.oUpperCnt, characteristic.oLowerCnt,
                characteristic.oUpperCnt, characteristic.oDigitsCnt);
        ln++;
    }
    return 0;
}
