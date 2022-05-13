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

int count_bits(int c){
    int cnt = 0, max_cnt = 0;
    char prev = 0;
    if (c == 0) return 0;
    for (int i = 0; i < sizeof(int)*8; ++i) {
//        printf("C: ");
//        PRINT_INT_BIN(c)
//        printf("; MASK: ");
//        PRINT_INT_BIN(1<<i)
//        printf("; RESULT: ");
//        PRINT_INT_BIN((c & (1<<i)))
//        printf("\n");
        if ((c & (1<<i)) != 0) {
            if (prev == 1) {
                cnt++;
                if (cnt > max_cnt) max_cnt = cnt;
            }
            else {
                cnt = 1;
                max_cnt = max_cnt > 1 ? max_cnt : 1;
            }
            prev = 1;
        } else {
            prev = 0;
        }
    }
    return max_cnt;
}

int main() {
    int d;
    scanf("%d", &d);
    printf("%d", count_bits(d));
    return 0;
}