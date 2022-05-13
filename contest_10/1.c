#include <stdio.h>
#include <math.h>
#define REENDIAN(X) (((X)>>24)&0xff) | (((X)<<8)&0xff0000) | (((X)>>8)&0xff00) | (((X)<<24)&0xff000000)

int main(){
    FILE * fd = fopen("input.bin", "rb");
    FILE * fo = fopen("output.bin", "wb");
    int n,t,c;
    double accum = 0;
    char change_endianess = 0;
    fread(&n, 4, 1, fd);
    fread(&t, 4, 1, fd);
    long long nn = n, tt = t;
    accum = floor((nn+tt)/2.0);
    c = (int) accum;
    fwrite(&c, 4, 1, fo);
    return 0;
}