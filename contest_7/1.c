#include <stdio.h>
#include <stdlib.h>

void ch_bytes(uint32_t *c, uint32_t *d) {
    uint32_t cp = (*c) & 0xffff0000,
            dp = (*d) & 0xffff;
    *d = ((*d) & 0xffff0000) + (cp >> 16);
    *c = ((*c) & 0xffff) + (dp << 16);
}

int main() {
    uint32_t a = 0xCAFEDEAD;
    uint32_t b = 0xDEADBEEF;
    printf("%X %X\n", a, b);
    ch_bytes(&a, &b);
    printf("%X %X\n", a, b);
    return 0;
}