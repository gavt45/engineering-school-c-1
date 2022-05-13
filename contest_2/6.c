#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int k,t;
    double pos=0,neg=0,zero=0,count=0;
    char f = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d",&t);
        pos += (t>0?1:0);
        neg += (t<0?1:0);
        zero += (t==0?1:0);
        count += 1;
    }
    printf("%.5f %.5f %.5f", neg/count,zero/count,pos/count);
    return 0;
}