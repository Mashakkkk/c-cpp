#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a, int n);
void output(int *a, int n);

int main() {
    int data[NMAX];

    if (input(data) != 0) {
        printf("n/a");
        return 0;
    }

    sort(data, NMAX);
    output(data, NMAX);

    return 0;
}

int input(int *a) {
    char k;
    for (int i = 0; i < NMAX; i++) {
        if ((scanf("%d%c", &a[i], &k) != 2) || (k != '\n' && k != ' ')) {
            return 1;
        }
    }
    return 0;
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}
