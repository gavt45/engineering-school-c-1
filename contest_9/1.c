#include <stdio.h>
#include <string.h>

int main(){
    FILE *fd = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout);
    int cnt = 0;
    int chr;

    while (1) {
        chr = fgetc(fd);
        if (chr == EOF) break;
        if (chr == '\n') cnt++;
    }
    printf("%d", cnt);
//    for (int j = 1; j < 1024; ++j) {
//        if (arr[j] > 0) printf("%d - %d\n", j, arr[j]);
//    }

    fclose(fd);
    return 0;
}
