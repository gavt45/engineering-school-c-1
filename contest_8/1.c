//
// Created by Gav on 22/10/2020.
//
#include <stdio.h>

int main() {
    int n,t,p;
//    freopen("output.txt", "w", stdout);
    scanf("%d", &n);

    double pDouble[1001 + 1][1001 + 1];

    for (int i = 0; i <= 1001; ++i) {
        pDouble[i][0] = 1;
        pDouble[i][i] = 1;

        for (int k=1; k < i; ++k)
            pDouble[i][k] = pDouble[i - 1][k - 1] + pDouble[i - 1][k];
    }

    for (int j = 0; j < n; ++j) {
        scanf("%d %d", &t, &p);
        printf("%0.10g\n", pDouble[t][p]);
    }
    return 0;
}
