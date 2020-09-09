#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int k,t;
    int max=-100000,min=100000,imax=-1,imin=-1;
    char f = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d",&t);
        if (t > max) {
            max = t;
            imax=i+1;
        }
        if (t < min) {
            min = t;
            imin=i+1;
        }
    }
    printf("%d %d %d %d", min, imin, max, imax);
    return 0;
}