#include <stdio.h>

int div(int a, int b) {
    int A = a;
    while (A >= b) {
        A -= b;
    }
    return A == 0;
}
int prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++) {
        if (div(n, i)) return 0;
    }
    return 1;
}
int main() {
    int a;
    char c;
    if ((scanf("%d%c", &a,&c) != 2) || (a == 0) || (a == 1) || (a == -1)) {
        printf("n/a");
        return 0;
    }
    if (a < 0) {
        a = -a;
    }
    int k = 1;
    for (int b = 2; b <= a; b++) {
        if (div(a, b) && prime(b)) {
            k = b;
        }
    }
    printf("%d", k);
    return 0;
}
