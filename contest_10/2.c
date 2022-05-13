#include <stdio.h>

#define REENDIAN(X) (((X)>>24)&0xff) | (((X)<<8)&0xff0000) | (((X)>>8)&0xff00) | (((X)<<24)&0xff000000)

int main(){
    FILE * fd = fopen("input.bin", "rb");
    FILE * fo = fopen("output.bin", "wb");
    int n,t;
    int accum = 0;
    char change_endianess = 0;
    fread(&n, 4, 1, fd);
    if (n > 10000) change_endianess = 1;
    if (change_endianess) n = REENDIAN(n);
    int i = 0;
    while (i < n) {
        size_t read_cnt = fread(&t, 4, 1, fd);
        if (read_cnt == 0) break;
        if (change_endianess) t = REENDIAN(t);
        accum += t;
        i++;
//        printf("Number: %X\n", t);
    }
    if (change_endianess) accum = REENDIAN(accum);
    fwrite(&accum, 4, 1, fo);
    return 0;
}