#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double x0, x1, x2;
    cout << "Enter two initial guesses: ";
    cin >> x0 >> x1;

    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    } while (fabs(f(x2)) >= 0.0001);

    cout << "Root is: " << x2 << endl;
    return 0;
}
