#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *a[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

int main() {
//    char b[100];
//    scanf("%[^\n]s",b);
//    for (int i = 0; i < 7; i++)
//    {
//        if (strcmp(a[i], b) == 0){
//            printf("%d", i+1);
//            break;
//        }
//    }
    char c = 'F', c1 = 'F';
    scanf("%c%c", &c, &c1);
    switch (c) {
        case 'M':
            printf("1");
            break;
        case 'T':
            if (c1 == 'u')
                printf("2");
            else
                printf("4");
            break;
        case 'W':
            printf("3");
            break;
        case 'F':
            printf("5");
            break;
        case 'S':
            if (c1 == 'u')
                printf("7");
            else
                printf("6");

    }

    return 0;
}