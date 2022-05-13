//
// Created by Gav on 07/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((y)>(x)?(y):(x))

int main() {
    char color[100];
    char codes[100];
    scanf("%s %s",color, codes);
    if (strcmp(color, "purple") == 0) {
        int a = strchr(codes, 'B')-codes+1; int b = strchr(codes, 'R')-codes+1;
        printf("%d %d", MIN(a,b), MAX(a,b));
    }else if (strcmp(color, "green") == 0) {
        int a = strchr(codes, 'B')-codes+1; int b = strchr(codes, 'Y')-codes+1;
        printf("%d %d", MIN(a,b), MAX(a,b));
    }else if (strcmp(color, "orange") == 0) {
        int a = strchr(codes, 'Y')-codes+1; int b = strchr(codes, 'R')-codes+1;
        printf("%d %d", MIN(a,b), MAX(a,b));
    }
    return 0;
}