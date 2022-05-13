#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int k;
    double t = 0.0,min=1.0;
    int imin=-1;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%lf",&t);
        t=fabs(t);
        // printf(" %lf ", (t-(int)t < 0.5 ? t-(int)t : 1 - (t-(int)t)));
        if ((t-(int)t < 0.5 ? t-(int)t : 1 - (t-(int)t)) < min) {
            min = (t-(int)t < 0.5 ? t-(int)t : 1 - (t-(int)t));
            imin=i+1;
        }
    }
    printf("%d", imin);
    return 0;
}
