// 多项式求解
#include <math.h>
#include <stdio.h>

double func(double x) {
    return 2 * pow(x, 11) - 3 * pow(x, 8) - 5 * pow(x, 3) - 1;
}

int main() {
    double start = 0., end = 2.;
    double x, res;
    do {
        x = (start + end) / 2.;
        res = func(x);
        printf("res=%f\n", res);
        if (func(x) * func(start) < 0) end = x;
        else start = x;
    } while (res < -0.0001 || res > 0.0001);
    printf("%f\n", x);
}