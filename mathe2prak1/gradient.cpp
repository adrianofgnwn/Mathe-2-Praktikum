#include "gradient.h"
#include <cmath>

// Function to compute the gradient numerically
CMyVektor gradient(CMyVektor x, double (*function)(CMyVektor x)) {
    
    const double h = 1e-8;
    int dimension = x.getDimension();
    CMyVektor gradient(dimension);

    for (int i = 0; i < dimension; ++i) {
        CMyVektor x_plus_h = x;
        x_plus_h[i] += h;
        double f_x_plus_h = function(x_plus_h);

        double f_x = function(x);

        gradient[i] = (f_x_plus_h - f_x) / h;
    }

    return gradient;
}