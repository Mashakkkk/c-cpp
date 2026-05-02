#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int search(int *a, int n, double mean_v, double variance_v);
void output(int result);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }

    double m = mean(data, n);
    double v = variance(data, n);
    int result = search(data, n, m, v);
    output(result);

    return 0;
}

int input(int *a, int *n) {
    if ((scanf("%d", n) != 1) || (*n <= 0 || *n > NMAX)) {
        return 1;
    }
    char k;
    for (int i = 0; i < *n; i++) {
        if ((scanf("%d%c", &a[i], &k) != 2) || (k != '\n' && k != ' ')) {
            return 1;
        }
    }
    return 0;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double m = mean(a, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] - m) * (a[i] - m);
    }
    return sum / n;
}

int search(int *a, int n, double mean_v, double variance_v) {
    double sigma = sqrt(variance_v);
    double uppb = mean_v + 3 * sigma;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && a[i] % 2 == 0 && a[i] >= mean_v && a[i] <= uppb) {
            return a[i];
        }
    }
    return 0;
}

void output(int result) { printf("%d", result); }
