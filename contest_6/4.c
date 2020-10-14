//
// Created by Gav on 07/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((y)>(x)?(y):(x))

char check_char(char * a, char * word){
    for (int i = 0; i < strlen(a); ++i) {
        if (strchr(word, a[i]) - word < strlen(word))
            return 0;
    }
    return 1;
}

int main() {
    char a[100];
    char word[100];
    scanf("%s", a);
    while (scanf("%s", word) == 1){
        if (check_char(a, word)){
            printf("%s\n", word);
        }
    }

}