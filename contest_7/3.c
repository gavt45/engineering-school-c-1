//
// Created by Gav on 19/10/2020.
//
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

void reverse(int c){
    PRINT_INT_BIN(c)
    printf("\n");
    for (int i = 0; i <= 16; i++) {
        char first_half = ((1<<(32-i))&c)!=0 ? 1:0;
        char second_half = ((1<<(i))&c)!=0 ? 1:0;
        c ^= (-second_half ^ c) & (1UL << (32-i));
        c ^= (-first_half ^ c) & (1UL << (i));
//        PRINT_INT_BIN(c)
//        printf("\n");
    }
    char fl = c&1;
//    printf("flag: %d\n", fl);
    c=c>>1;
    c ^= (-fl^c) & (1UL << 31);
    printf("%d\n", c);
    PRINT_INT_BIN(c)
}

int main() {
    int d;
    scanf("%d", &d);
    reverse(d);
    return 0;
}
