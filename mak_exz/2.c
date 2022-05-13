#include <stdlib.h>
#include <stdio.h>

/*
 * func Находит максимальную цифру в десятичной записи числа num и выводит её.
 */
void func(int num){
    int m = -1;
    while (num > 0){
        if (num % 10 > m) m = num % 10;
        num /= 10;
    }
    printf("%d\n", m);
}

int main(){
    int n = 1;
    func(n); // 1
    n = 712;
    func(n); // 7
    n = 918;
    func(n); // 9
    n = 198;
    func(n); // 9
    n = 189;
    func(n); // 9
}