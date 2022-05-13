//
// Created by Gav on 28/10/2020.
//
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fd = fopen("input.txt", "r");
    FILE *fo = fopen("output.txt", "w");

//    char line[3 * 1000000 + 1];//[2000001];
//    size_t len = 0;
//    size_t read;

//    fprintf(fd, " \n");
//    rewind(fd);
    fseek(fd, 0, SEEK_END);
    int sz = ftell(fd);
    rewind(fd);

    char * line = (char*) malloc(sz+1);

    fread(line, sizeof(char), sz, fd);

    line[sz] = '\0';

//    printf("LINE: %s", line);

    char * q = line + sz;

    char first_out = 1;
    char nl_end = 0;

    while (q >= line) {
//        printf("char: %X [%c] q: %d\n", *q, *q, q-line);
        if (*q == '\n') {
//            printf("puts: %s\n", q+1);
            int sz1 = fputs(q+1, fo);
//            printf("sz: %d first_out: %d line: [%s]\n", sz1, first_out, q+1);
            if (first_out == 1){
                if (sz1 == 0){
                    nl_end = 1;
                }
                first_out = 0;
            }
            if (sz1 != 0){
                fprintf(fo, "\r\n");
            }
            *(q-1) = '\0';
            *q = '\0';
        }else if (q == line){
//            printf("puts: %s\n", q);
            int sz1 = fputs(q, fo);
            if (nl_end){
                fprintf(fo, "\r\n");
            }
//            printf("sz: %d first_out: %d line: [%s]\n", sz1, first_out, q);
        }
        q--;
    }

////    printf("line cnt: %d\n", s);
////
////    for (int i = 0; i < s; ++i) {
////        printf("%d: %d\n", i, a[i]);
////    }
//
////    rewind(fd);
////    c -= 1;
//    c = s-1;
//
//    fseek(fd, 0, SEEK_END); // seek to end
//
////    printf("Before cycle: %d\n", ftell(fd));
//
//    long long pos = ftell(fd);
//
//    while (c >= 0) {
////        printf("c: %d seek: %d pos: %d\n", c, -a[c]+1, ftell(fd));
//        pos -= a[c]+1;
//        fseek(fd, pos, SEEK_SET);
//        fgets(line, sizeof(line), fd);
//        l = strlen(line);
//        if (line[l-1] == '\n') line[l-1] = '\0';
//        printf("%s", line);
//        if (c != 0) printf("\n");
////        if (c == s-1) printf("\n");
//        c--;
//    }
    return 0;
}

