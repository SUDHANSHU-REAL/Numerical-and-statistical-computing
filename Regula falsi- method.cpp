#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 2;
}

int main() {
    double a, b, c;
    cout << "Enter a and b: ";
    cin >> a >> b;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval!" << endl;
        return 0;
    }

    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) == 0.0) break;
        (f(a) * f(c) < 0) ? b = c : a = c;
    } while (fabs(f(c)) > 0.0001);

    cout << "Root is: " << c << endl;
    return 0;
}
