//
// Created by Gav on 11/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Label_s {
    char name [16]; //имя автора (заканчивается нулём)
    int age ; //возраст автора (сколько лет)
} Label ;

typedef struct NameStats_s {
    int cntTotal ; //сколько всего подписей
    int cntLong ; //сколько подписей с именами длиннее 10 букв
} NameStats ;

typedef struct AgeStats_s {
    int cntTotal ; //сколько всего подписей
    int cntAdults ; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids ; //сколько подписей детей (меньше 14 лет)
} AgeStats ;

void calcStats ( const Label * arr , int cnt , NameStats * oNames , AgeStats * oAges ){
    oNames->cntTotal = cnt;
    oNames->cntLong = 0;
    oAges->cntTotal = cnt;
    oAges->cntKids = 0;
    oAges->cntAdults = 0;
    for (int i = 0; i < cnt; ++i) {
        if (strlen(arr[i].name) > 10) oNames->cntLong++;
        if (arr[i].age < 14) oAges->cntKids++;
        if (arr[i].age >= 18) oAges->cntAdults++;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Label * arr = (Label*)malloc(n * sizeof(Label));
    NameStats oNames; AgeStats oAges;
    char shit[256];

    for (int i = 0; i < n; ++i) {
        memset(arr[i].name, 0, 16);
        scanf("%s %d %s", arr[i].name, &arr[i].age, shit);
    }
    calcStats(arr, n, &oNames, &oAges);

    printf("names: total = %d\n", oNames.cntTotal);
    printf("names: long = %d\n", oNames.cntLong);
    printf("ages: total = %d\n", oAges.cntTotal);
    printf("ages: adult = %d\n", oAges.cntAdults);
    printf("ages: kid = %d\n", oAges.cntKids);
    return 0;
}
