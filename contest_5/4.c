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
    char c = 'F', last;
    int sum = 0;
    while (c != '.') {
        scanf("%c", &c);
        if (c!='.') {
            sum += c-'0';
            last = c;
        }
    }

    if ((last == '0' || last == '5') && sum % 3 == 0){
        printf("YES");
        return 0;
    }
    printf("NO");


    return 0;
}

