//
// Created by Gav on 30/10/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a)>(b) ? (a) : (b))

void print_row_sep(int max_id_len, int max_cnt_len, int max_time_len) {
    printf("+");
    for (int i = 0; i < max_id_len + 2; ++i) {
        printf("-");
    }
    printf("+");
    for (int i = 0; i < max_cnt_len + 2; ++i) {
        printf("-");
    }
    printf("+");
    for (int i = 0; i < max_time_len + 2; ++i) {
        printf("-");
    }
    printf("+\n");
}

void space_pad(int cnt) {
    for (int i = 0; i < cnt; ++i) {
        printf(" ");
    }
}

int main() {
    FILE *fd = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout);
    int times[1001] = {0};
    int cnts[1001] = {0};
    int max_id_len = 1, max_cnt_len = 1, max_time_len = 1;
    int n, id, k;

    fscanf(fd, "%d", &n);

    for (int i = 0; i < n; ++i) {
        fscanf(fd, "%d %d", &id, &k);
        cnts[id]++;
        times[id] += k;
        max_id_len = MAX(max_id_len, (int) log10(id) + 1);
        max_cnt_len = MAX(max_cnt_len, (int) log10(cnts[id]) + 1);
        max_time_len = MAX(max_time_len, (int) log10(times[id]) + 1);
    }

    for (int j = 0; j < 1001; ++j) {
        if (cnts[j] != 0) {
            print_row_sep(max_id_len, max_cnt_len, max_time_len);
            printf("| ");
            // padd with spaces
            space_pad(max_id_len - (int) log10(j) - 1);
            printf("%d", j);

            printf(" | ");
            space_pad(max_cnt_len - (int) log10(cnts[j]) - 1);
            printf("%d", cnts[j]);

            printf(" | ");
            space_pad(max_time_len - (int) log10(times[j]) - 1);
            printf("%d", times[j]);
            printf(" |\n");
        }
    }

    print_row_sep(max_id_len, max_cnt_len, max_time_len);
    return 0;
}
