//
// Created by Gav on 28/10/2020.
//
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fd = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout);

    int a[100000], s = 0, c = 0, l;
    char line[2000001];
    size_t len = 0;
    size_t read;

//    fprintf(fd, " \n");
//    rewind(fd);

    while (fgets(line, sizeof(line), fd)) {
//        printf("Retrieved line of length %zu:\n", read);
//        printf("%s\n", line);
        a[s] = strlen(line);
        s++;
    }

//    printf("line cnt: %d\n", s);
//
//    for (int i = 0; i < s; ++i) {
//        printf("%d: %d\n", i, a[i]);
//    }

//    rewind(fd);
//    c -= 1;
    c = s-1;

    fseek(fd, 0, SEEK_END); // seek to end

//    printf("Before cycle: %d\n", ftell(fd));

    long long pos = ftell(fd);

    while (c >= 0) {
//        printf("c: %d seek: %d pos: %d\n", c, -a[c]+1, ftell(fd));
        pos -= a[c]+1;
        fseek(fd, pos, SEEK_SET);
        fgets(line, sizeof(line), fd);
        l = strlen(line);
        if (line[l-1] == '\n') line[l-1] = '\0';
        printf("%s", line);
        if (c != 0) printf("\n");
//        if (c == s-1) printf("\n");
        c--;
    }
    return 0;
}
