//
// Created by Gav on 30/09/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_NUM(x) ((x) >= '0' && (x) <= '9')

int main(){
    freopen("input.txt", "r", stdin);
    FILE * in = fopen("input.txt", "r");
//    freopen("output.txt", "w", stdout);
    char c = 'F', last = 'F';
    int sum = 0;
    int last_num = 0;
    while (c != '.'){
//        scanf(" %c", &c, 1);
        c = (char)fgetc(in);
//        printf("c: %c\n", c);
//        if (c!='.'){
            if (IS_NUM(c) && IS_NUM(last)){
                last_num *= 10;
                last_num += c-'0';
            } else if (IS_NUM(c) && !IS_NUM(last)) {
                last_num = c-'0';
            } else if (IS_NUM(last) && !IS_NUM(c)) {
//                printf("LAST NUM: %d\n", last_num);
                sum += last_num;
                last_num = 0;
            }
//        }
        last = c;
    }

    printf("%d", sum);

    return 0;
}



