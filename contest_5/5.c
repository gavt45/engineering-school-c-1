//
// Created by Gav on 30/09/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char c = 'F', last = '.';
    int count = 0;
    while (c!='\n'){
        scanf("%c", &c);
        if ((c == '.'||c=='\n') && last != '.'){
            count++;
        }
        last = c;
    }

    printf("%d", count);
    return 0;
}


