//
// Created by Gav on 30/09/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * a[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main(){
    char b[14];
    char *e;
    int index;
    scanf("%[^\n]s",b);
    e = strchr(b, '.');
    index = (int)(e - b);
//    printf("INDEX: %d", index);
    if (index != 3 || b[1] != 'A'){
        printf("DOES NOT FIT\n");
        return 0;
    }
    printf("FITS\n");
    return 0;
}
