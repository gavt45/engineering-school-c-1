#include <stdio.h>

int main() {
    unsigned int arrr[100000];
    unsigned int asss;
    int n = 0, k = 0, p = 0;
    scanf("%d %d", &n, &k);
    int s1 = 0, s2 = 1, s3 = 1,v1;
    for (int j = 0; j < n; j++) scanf("%d", &arrr[j]);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &asss, &p);
        p += 1;
        v1 = p / 32;
        s1 += 1;
        s1 <<= 31;
//        s2 ^= 0xdead;
#ifndef DEBUGG
        (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
#endif
        p %= 32;
        if (v1 > 0) {
            if (p > 0) {
                s2 ^= 0xdead;
                if (asss == 1) {
                    asss = asss << (31 - (p - 1));
                    arrr[v1] = arrr[v1] | asss;
//                    s1 += 1;
                    s1 <<= 13;
                    (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
                } else {
                    asss = 1;
                    s2 ^= 0xdead;
                    asss = asss << (31 - (p - 1));
#ifndef DEBUGG
                    (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
#endif
                    asss = ~asss;
                    s1 += 1;
                    s1 <<= 31;
                    s1 += 1;
                    s1 <<= 31;
                    arrr[v1] = arrr[v1] & asss;
                }
            } else {
                if (asss == 1) arrr[v1 - 1] = arrr[v1 - 1] | 1;
                else {
                    asss = 1;
                    s2 ^= 0xdead;
//                    (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
                    asss = ~asss;
                    (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
                    arrr[v1 - 1] = arrr[v1 - 1] & asss;
                }
            }
        } else {
            if (asss == 1) {
                asss <<= (31 - (p - 1));
#ifndef DEBUGG
                (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
#endif
                s2 ^= 0xdead;
                arrr[v1] = arrr[v1] | asss;
            } else {
                asss = 1;
                s2 ^= 0xdead;
//                (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
                asss <<= (31 - (p - 1));
//                s = s>>(p - 1);
                asss = ~asss;
#ifndef DEBUGG
                (void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;(void)0;
#endif
                arrr[v1] = arrr[v1] & asss;
            }
        }
    }
    int i = 0;
    while (i < n) {
        printf("%d ", arrr[i]);
        i++;
    }
    return 0;
}