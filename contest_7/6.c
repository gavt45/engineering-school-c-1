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

//какой-нибудь целочисленный тип (желательно беззнаковый)
typedef int bitword;

//инициализирует массив битов длины num, устанавливая все его биты в ноль
void bitsetZero ( bitword * arr , int num ){
    for (int i = 0; i < num/(sizeof(bitword)*8)+1; ++i) {
        arr[i] = 0;
    }
}

//возвращает значение idx-ого бита (0 или 1)
int bitsetGet ( const bitword * arr , int idx ){
    return ( arr[idx/(sizeof(bitword)*8)] >> (idx % (sizeof(bitword) * 8)) ) & 1UL;
}

//устанавливает значение idx-ого бита в newval (которое равно 0 или 1)
void bitsetSet ( bitword * arr , int idx , unsigned int newval){
    bitword c = arr[idx/(sizeof(bitword)*8)];
    c ^= (-newval ^ c) & (1UL << (idx % (sizeof(bitword) * 8)));
    arr[idx/(sizeof(bitword) * 8)] = c;
}

//возвращает 1, если среди битов с номерами k
//для left <= k < right есть единичный, и 0 иначе
int bitsetAny ( const bitword * arr , int left , int right ){
    // todo test
    right -= 1;
    //

    unsigned int nl = left/(sizeof(bitword) * 8);
    unsigned int l_offset = left % (sizeof(bitword) * 8);
    unsigned int nr = right/(sizeof(bitword) * 8);
    unsigned int r_offset = right % (sizeof(bitword) * 8);
//    printf("nl: %d l_offset: %d nr: %d r_offset: %d\n", nl,l_offset,nr,r_offset);
    for (unsigned int cnt = nl; cnt <= nr; ++cnt) {
        unsigned int mask = 0xFFFFFFFF; //todo implementation specific
        if (cnt == nl)
            mask <<= l_offset;
        else if (cnt == nr)
            mask >>= (sizeof(bitword)*8 - r_offset);
//        printf("i: %d; MASK: ", cnt);
//        PRINT_INT_BIN(mask)
//        printf("\n");
        if ((arr[cnt] & mask) != 0)
            return 1;
    }
//    0xFFFFFFFF << ;
    return 0;
}

int main() {
    int n = 0, m = 0;
    int choice = 0, num = 0, idx = 0, new_val = 0, left = 0, right = 0;
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);

    bitword *arrr = (bitword *) malloc(n * sizeof(bitword));
//    bitsetZero(arrr, 100);
//    bitsetSet(arrr, 0, 1);
//    bitsetSet(arrr, 2, 1);
//    bitsetSet(arrr, 62, 1);
//    bitsetSet(arrr, 69, 1);
//    bitsetSet(arrr, 31, 1);
//    bitsetSet(arrr, 32, 1);
//    bitsetSet(arrr, 33, 1);
//    bitsetSet(arrr, 100, 1);
//    PRINT_INT_BIN(arrr[3])
//    printf("  ");
//    PRINT_INT_BIN(arrr[2])
//    printf("  ");
//    PRINT_INT_BIN(arrr[1])
//    printf("  ");
//    PRINT_INT_BIN(arrr[0])
//    printf("\n");
//    printf("%d\n", bitsetGet(arrr, 30));
//    printf("%d\n", bitsetGet(arrr, 31));
//    printf("%d\n", bitsetGet(arrr, 34));
//    bitsetAny(arrr, 30, 70);
//    bitsetAny(arrr, 30, 31);
//    bitsetAny(arrr, 31, 31);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &choice, &idx);
        bitsetSet(arrr, idx, choice != 0 ? 1 : 0);
    }
    PRINT_INT_BIN(arrr[1])
    printf("  ");
    PRINT_INT_BIN(arrr[0])
    printf("\n");
    for (int j = 0; j < n; ++j) {
        printf("%d ", arrr[j]);
    }
    return 0;
}

