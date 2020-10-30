//
// Created by Gav on 25/10/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //            cols      rows
    int x = 0, y = 0, x_sz = 0, y_sz = 0, x_start = 0;
    char c;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &y_sz, &x_sz, &x);
    x--;
    x_start = x;
    scanf("%c", &c);
    char **f = (char **) malloc(y_sz * sizeof(char *));
    int **used = (int **) malloc(y_sz * sizeof(int *));
    for (int i = 0; i < y_sz; ++i) {
        f[i] = (char *) malloc(x_sz * sizeof(char));
//        scanf("%[^\n]s", f[i]);
        used[i] = (int *) malloc(x_sz * sizeof(int));
        for (int j = 0; j < x_sz; ++j) {
            scanf("%c", &f[i][j]);
            used[i][j] = 0;
        }
        scanf("%c", &c);
    }
//    char ok = 1;
    int step_count = 0;
    while (1) {
        if (x >= x_sz || y >= y_sz || x < 0 || y < 0) {
            printf("%d step(s) to exit", step_count);
            break; // if we are out of bounds
        }
        if (used[y][x] != 0) {
            int v = 0;
            if (y == 0 && (x == x_start-1 || x == x_start + 1)) {
                used[y][x] = 0;
                v = 1;
            }
//            printf("used[%d][%d] = %d\n", y_prev, x_prev, used[y_prev][x_prev]);
//            printf("used[%d][%d] = %d\n", y, x, used[y][x]);
            printf("%d step(s) before a loop of %d step(s)", used[y][x], step_count - used[y][x] - v);
            break; // if we are in cycle
        }

        used[y][x] = step_count;
        step_count++;

//        x_start = 0;

        switch (f[y][x]) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }

    }

    return 0;
}