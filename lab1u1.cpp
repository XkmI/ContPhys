#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main() {
    const double PI = 3.141592653589793;
    const int nTpts = 7901; const int nXpts = 21; double tMax = 10.0; double xMax = 1.0;
    double dx = xMax/double(nXpts-1); double dt = tMax/double(nTpts-1);
    double y[nTpts][nXpts] = {0};

    ofstream dataFile("l1u1.dat");
    // Initial condition
    for (int j = 0; j < nXpts; j++) {
        y[0][j] = sin(PI * j*dx);
        dataFile << y[0][j] << " ";
    }

    for (int i = 1; i < nTpts; i++) {
        dataFile << "\n";
        for (int j = 0; j < nXpts; j++) {
            if (j == 0 || j == nXpts-1) {
                y[i][j] = 0;
            } else {
                y[i][j] = y[i-1][j] + dt/(dx*dx) * (y[i-1][j+1] - 2*y[i-1][j] + y[i-1][j-1]);
            }
            dataFile << y[i][j] << " ";
        }
    }

    dataFile.close();

    cout << dt/(dx*dx) << "\n";
    cout << y[nTpts-1][(nXpts-1)/2] << "\n";

    return 0;
}