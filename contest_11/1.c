#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct DateTime_s {
    int year , month , day ;
    int hours , minutes , seconds ;
} DateTime ;

DateTime min (const DateTime * arr, int cnt) {
    long long max_c = 99999999245959, c = 0; // YYYYMMDDHHmmss
    DateTime max_date;
    for (int i = 0; i < cnt; ++i) {
        c=0;
        c+= (arr[i].year) * (ll)1e10L + (arr[i].month) * 1e8L + (arr[i].day) * 1e6L +
                (arr[i].hours) * 1e4L + (arr[i].minutes) * 1e2L + (arr[i].seconds);
//        printf("C: %lld\n", c);
        if (c < max_c){
            max_date = arr[i];
            max_c = c;
        }
    }
    return max_date;
}

int main(){
    int n;
    scanf("%d", &n);
    DateTime * date = (DateTime*)malloc(n * sizeof(DateTime));
    for (int i = 0; i < n; ++i) {
//        DateTime date;
        scanf("%d %d %d %d %d %d", &date[i].year, &date[i].month, &date[i].day, &date[i].hours, &date[i].minutes, &date[i].seconds);
    }
    DateTime mind = min(date, n);
    printf("%d %d %d %d %d %d", mind.year, mind.month, mind.day, mind.hours, mind.minutes, mind.seconds);
    return 0;
}