#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 2;
}

double df(double x) {
    return 3 * x * x - 1;
}

int main() {
    double x;
    cout << "Enter initial guess: ";
    cin >> x;

    double h;
    do {
        h = f(x) / df(x);
        x = x - h;
    } while (fabs(h) >= 0.0001);

    cout << "Root is: " << x << endl;
    return 0;
}
