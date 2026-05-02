#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
void cyclic_shift(int *a, int n, int c);

int main() {
    int n, c;
    int data[NMAX];

    if (input(data, &n, &c) != 0) {
        printf("n/a");
        return 0;
    }

    cyclic_shift(data, n, c);
    output(data, n);

    return 0;
}

int input(int *a, int *n, int *c) {
    char k;
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", &a[i], &k) != 2 || (k != '\n' && k != ' ')) {
            return 1;
        }
    }
    if (scanf("%d", c) != 1) {
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}

void cyclic_shift(int *a, int n, int c) {
    int shift = c % n;
    if (shift < 0) shift += n;

    if (shift == 0) return;

    int x[NMAX];

    for (int i = 0; i < n - shift; i++) {
        x[i] = a[shift + i];
    }

    for (int i = 0; i < shift; i++) {
        x[n - shift + i] = a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = x[i];
    }
}
