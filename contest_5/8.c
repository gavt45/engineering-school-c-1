//
// Created by Gav on 30/09/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * a[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main() {
    char c = 'F', last = -1;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (1) {
        if (scanf("%c", &c) != 1)
            break;
        if (last == '/' && c == '/') { // delete all string (read until /n or EOF)
//            printf("|NOT PRINTING //|");
            while (c != '\n'){
                scanf("%c", &c);
            }
            last = -1;
        } else if (last == '/' && c == '*'){ // delete multiple rows (read until */ or EOF)
            while (last != '*' || c != '/'){
                last = c;
                scanf("%c", &c);
                if (c == '\n')
                    printf("\n");
            }
            last = -2;
        }
        if (last >= 0) {
            printf("%c", last);
            last = c;
        } else{
            last++;
            if (last == 0){
                last = c;
            }
        }
    }
    return 0;
}