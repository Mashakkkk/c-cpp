#include <math.h>
#include <stdio.h>

#define pi 3.14159265358979323846
#define steps 41
#define points 42

double versiera(double x) { return 1.0 / (1.0 + x * x); }
double lemniscate(double x) {
    double inner = sqrt(sqrt(1.0 + 4.0 * x * x) - x * x - 1.0);
    if (inner < 0.0) {
        return NAN;
    }
    return sqrt(inner);
}

double hyperbola(double x) {
    if (x == 0.0) {
        return NAN;
    }
    return 1.0 / (x * x);
}

void print_value(double val) {
    if (isnan(val)) {
        printf("-");
    } else {
        printf("%.7f", val);
    }
}

int main() {
    double step = (2.0 * pi) / steps;

    for (int i = 0; i < points; i++) {
        double x = -pi + i * step;

        double v = versiera(x);
        double l = lemniscate(x);
        double h = hyperbola(x);

        printf("%.7f | ", x);
        print_value(v);
        printf(" | ");
        print_value(l);
        printf(" | ");
        print_value(h);
        printf("\n");
    }

    return 0;
}
