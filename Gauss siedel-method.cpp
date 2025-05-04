#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a[3][4] = {
        {4, -1, 0, 3},
        {-1, 4, -1, 5},
        {0, -1, 4, 6}
    };
    float x[3] = {0}, old[3];
    int i, j;
    float error = 0.001;

    do {
        for (i = 0; i < 3; i++) old[i] = x[i];
        for (i = 0; i < 3; i++) {
            x[i] = a[i][3];
            for (j = 0; j < 3; j++)
                if (i != j) x[i] -= a[i][j] * x[j];
            x[i] /= a[i][i];
        }
    } while (fabs(x[0]-old[0]) > error || fabs(x[1]-old[1]) > error || fabs(x[2]-old[2]) > error);

    for (i = 0; i < 3; i++) cout << "x" << i+1 << " = " << x[i] << endl;
    return 0;
}
