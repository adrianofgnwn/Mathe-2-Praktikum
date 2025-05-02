#include <iostream>
#include "CMyMatrix.h"

CMyVektor f1(CMyVektor x)
{
    //x[0] = x1, x[1]= x2, x[2] = x3, x[3] = x4
    CMyVektor v(3);
    v[0] = x[0] * x[1] * exp(x[2]); //x1 * x2 * e^x3
    v[1] = x[1] * x[2] * x[3]; //x2 * x3 * x4
    v[2] = x[3]; //x4

    return v;
}

CMyVektor f2(CMyVektor x)
{
    //x[0] = x, x[1] = y
    CMyVektor v(2);
    v[0] = pow(x[0],3) * pow(x[1],3) - 2*x[1]; //x^3 * y^3 - 2y
    v[1] = x[0] - 2; //x -2

    return v;
}

int main()
{
    CMyVektor x_start1(4);
    x_start1[0] = 1;
    x_start1[1] = 2;
    x_start1[2] = 0;
    x_start1[3] = 3;

    std::cout << jacobi(x_start1, f1) << std::endl << std::endl;

    CMyVektor x_start2(2);
    x_start2[0] = 1;
    x_start2[1] = 1;

    std::cout << NewtonVerfahren(x_start2, f2) << std::endl << std::endl;

    return 0;

}
