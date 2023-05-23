#include "stdio.h"
#include <string.h>

int main()
{
    const int n = 4;
    double v[n] = { 1, 2, 3, 4 };
    double p[n + 1] = { 0, 0, 0, -v[0], 1 };
    double pt[n + 1] = { 0 };
    double C[n] = {0};
    double Cp[n] = { 0 };

    C[0] = 1;

    for (int i = 1; i < n; i++) {
        memcpy(pt, p, sizeof(double) * (n + 1));
        for (int j = 0; j < i + 1; j++) {
            p[n - i + j - 1] = pt[n - i + j - 1] - v[i] * pt[n - i + j];
        }

        memcpy(Cp, C, sizeof(double) * n);
        for (int j = 0; j < i; j++) {
            C[j] = Cp[j] / (v[j] - v[i]);
            C[i] -= C[j];
        }
    }

    double B[n][n] = { 0 };
    double c[n] = { 0 };

    for (int i = 0; i < n; i++) {
        c[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            c[j] = p[j + 1] + v[i] * c[j + 1];
        }
        for (int j = 0; j < n; j++) {
            B[i][j] = c[j] * C[i];
        }
    }

    return 1;
    
}
