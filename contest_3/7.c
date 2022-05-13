// int l = -1
// int r = len(a)   
// while l < r - 1                // С помощью бинарного поиска найдем максимум на массиве
//     m = (l + r) / 2            // m — середина области поиска
//     if a[m] > a[n - 1]         // Сужение границ
//         l = m
//     else 
//         r = m
// int x = l                      // x — искомый индекс.


#include <stdlib.h>
#include <stdio.h>
// #include <malloc>

typedef long long ll;

int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    int * a = (int*)malloc(n * sizeof(int));
    // int * t = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        // a[t+1000] += 1;
    }

    int l = 0,m,x=-1;
    int r = n-1;
    while (l <= r){
        m = (l + r) / 2;
        if (a[m] == t){
            x = m;
            break;
        }
        if (a[m] <= t)
            l = m+1;
        else
            r = m-1;
    // int x = l
    }
    printf("%d", x);
    return 0;
}
