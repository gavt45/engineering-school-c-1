//
// Created by Gav on 19/10/2020.
//
#include <stdio.h>
#include <stdlib.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

#define PRINT_INT_BIN(a) printf(BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN""BYTE_TO_BINARY_PATTERN, \
                                    BYTE_TO_BINARY((a)>>24), BYTE_TO_BINARY((a)>>16), \
                                    BYTE_TO_BINARY((a)>>8), BYTE_TO_BINARY(a));

int main() {
    int n;
    int t = 0;
    char cnt = 0;
    char c;
    scanf("%d", &n);
    scanf("%c", &c); // scan garbage \n
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c);
        char tt = c == '1' ? 1 : 0;
        t |= tt << cnt;
//        printf("\n%d\n", tt);
        cnt = (cnt+1)%8;
//        PRINT_INT_BIN(t)
//        printf("\n");
        if (cnt == 0) {
            printf("%d ", t);
            cnt = 0;
            t = 0;
        }
    }
    if (n % 8 != 0) printf("%d",t);
    return 0;
}
