#include <stdio.h>
#include <math.h>

double f(double x) {
    // Example function: x^3 - x - 2
    return x*x*x - x - 2;
}

double bisection(double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("Function has the same signs at the ends of interval [a,b].\\n");
        return NAN;
    }

    double c;
    for (int i = 0; i < max_iter; i++) {
        c = (a + b) / 2;
        double fc = f(c);

        if (fabs(fc) < tol || (b - a) / 2 < tol) {
            return c;
        }

        if (f(a) * fc < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return (a + b) / 2;
}

int main() {
    double a = 1, b = 2;
    double tol = 1e-5;
    int max_iter = 100;

    double root = bisection(a, b, tol, max_iter);
    if (!isnan(root)) {
        printf("Root found: %lf\\n", root);
    } else {
        printf("Bisection method failed to find a root.\\n");
    }

    return 0;
}
