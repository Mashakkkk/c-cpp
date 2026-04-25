#include <stdio.h>
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("n/a");
        return 0;
    }
    int a = fib(n);
    printf("%d", a);
    return 0;
}
