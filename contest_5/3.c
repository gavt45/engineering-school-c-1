//
// Created by Gav on 30/09/2020.
//

//
// Created by Gav on 30/09/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char c = 'F', last = 'F', last1 = 'F';
    scanf("%c", &last1);
    if (last1 == '.') return 0;
    scanf("%c", &last);
    printf("%c", last1);
    if (last == '.') {
        return 0;
    }
    scanf("%c", &c);
    while (c!='.'){
        printf("%c", last);
        last1 = last;
        last = c;
        scanf("%c", &c);
    }
    if (last1 == 'e' && last == 'r'){
        printf("st");
    } else if (last == 'e'){
        printf("%c", last);
        printf("r");
    } else {
        printf("%c", last);
        printf("er");
    }
//    printf("\nlast1: %c last: %c c: %c",last1,last,c);
//    printf("%d", count);
    return 0;
}



