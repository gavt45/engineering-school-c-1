//
// Created by Gav on 20/10/2020.
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

typedef unsigned int bitword;

void bitsetZero(bitword *arr, int num) {
    for (int i = 0; i < (num/(sizeof(bitword) * 8))+1; i++) arr[i] = 0;
}

int bitsetGet(const bitword *arr, int idx) {
//    idx = idx % (sizeof(bitword) * 8);
    idx -= 1;
    PRINT_INT_BIN(arr[0])
    printf("\n");
    PRINT_INT_BIN(arr[1])
    printf("\n");
    printf("n: %d/32 = %d\n", idx, idx/(sizeof(bitword) * 8));
    PRINT_INT_BIN(((sizeof(bitword) * 8) - idx%(sizeof(bitword) * 8)))
    printf("\n");
    return (arr[idx/(sizeof(bitword) * 8)] & (1 << ((sizeof(bitword) * 8) - idx%(sizeof(bitword) * 8))))
                >> (((sizeof(bitword) * 8) - idx%(sizeof(bitword) * 8)));
}

void bitsetSet(bitword *arr, int idx, int newval) {
    int n = idx / (sizeof(bitword) * 8);
    idx %= (sizeof(bitword) * 8);
    unsigned int a;
    if (n > 0) {
        if (idx > 0) {
            if (newval == 1) {
                a = 1;
                a = a << (sizeof(bitword) * 8 - 1);
                a = a >> (idx - 1);
                arr[n] = arr[n] | a;
            } else {
                a = 1;
                a = a << (sizeof(bitword) * 8 - 1);
                a = a >> (idx - 1);
                a = ~a;
                arr[n] = arr[n] & a;
            }
        } else {
            if (newval == 1) arr[n - 1] = arr[n - 1] | 1;
            else {
                a = 1;
                a = ~a;
                arr[n - 1] = arr[n - 1] & a;
            }
        }
    } else {
        if (newval == 1) {
            a = 1;
            a = a << (sizeof(bitword) * 8 - 1);
            a = a >> (idx - 1);
            arr[n] = arr[n] | a;
        } else {
            a = 1;
            a = a << (sizeof(bitword) * 8 - 1);
            a = a >> (idx - 1);
            a = ~a;
            arr[n] = arr[n] & a;
        }
    }
}

int bitsetAny(const bitword *arr, int left, int right) {
    for (int bit = left; bit < right; ++bit) {
        if (bitsetGet(arr, bit)) return 1;
    }
    return 0;
}

int main() {
    int n = 0, s = 0, num = 0, idx = 0, newlal = 0, left = 0, right = 0;
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    bitword *arrr = (bitword *) malloc(100 * sizeof(bitword));
    for (int i = 0; i < n; i++) {
        scanf("%d", &s);
        switch (s) {
            case 0:
                scanf("%d", &num);
                free(arrr);
//                printf("before %X\n", arrr);
                arrr = (bitword *) malloc((num / (sizeof(bitword) * 8 + 1)) * sizeof(bitword));
//                printf("after %X\n", arrr);
                bitsetZero(arrr, num);
                break;
            case 1:
                scanf("%d", &idx);
                s = bitsetGet(arrr, idx);
                printf("%d\n", s);
                break;
            case 2:
                scanf("%d %d", &idx, &newlal);
                bitsetSet(arrr, idx, newlal);
                break;
            case 3:
                scanf("%d %d", &left, &right);

                if (bitsetAny(arrr, left, right)) {
                    printf("some\n");
                } else {
                    printf("none\n");
                }
                break;
        }
    }
    return 0;
}
