#include <stdio.h>
#include <stdlib.h>


int main(){
    int n,m;
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    int **mat = (int **)malloc(n * sizeof(int*));
    for (int row = 0; row < n; ++row) {
        mat[row] = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; ++i) {
            scanf("%d", &mat[row][i]);
        }
    }

    for (int row = 0; row < n; ++row) {
        int cnt = 0;
        for (int col = 0; col < m; ++col) {
            if (cnt != 0 && mat[row][col] == 0) {
                printf("%d ", cnt);
                cnt = 0;
            }

            if (mat[row][col] == 1)
                cnt++;

        }
        if (cnt != 0)
            printf("%d\n", cnt);
//            else            printf("%d", cnt);
        else
            printf("\n");
    }

    for (int col1 = 0; col1 < m; ++col1) {
        int cnt = 0;
        for (int row1 = 0; row1 < n; ++row1) {
            if (cnt != 0 && mat[row1][col1] == 0) {
                printf("%d ", cnt);
                cnt = 0;
            }

            if (mat[row1][col1] == 1)
                cnt++;

        }
        if (cnt != 0)
            printf("%d\n", cnt);
//            else             printf("%d", cnt);
        else
            printf("\n");
    }

    return 0;
}