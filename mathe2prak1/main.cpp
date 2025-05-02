#include <iostream>
#include "CMyVektor.h"
#include "gradient.h"
#include "gradientverfahren.h"


//Sample function f(x, y) = 4x^2 + 4yz^2
double sampleFunction(CMyVektor x) {
    return (4 * pow(x[0], 2)) + (4* x[1] * pow(x[2],2));
}

double f(CMyVektor x)
{
    return sin(x[0] * x[1]) + sin(x[0]) + cos(x[1]); //x[0] = x, x[1] = y
}
double g(CMyVektor x)
{
    return -((2 * x[0] * x[0]) - (2 * x[0] * x[1]) + (x[1] * x[1]) + (x[2] * x[2]) - (2 * x[0]) - (4 * x[2]));
}

int main() {

    //Vektor test
    /*
    CMyVektor v1(3);
    v1.setKomponente(0, 1.0);
    v1.setKomponente(1, 2.0);
    v1.setKomponente(2, 3.0);

    std::cout << "Vector v1: ";
    for (int i = 0; i < v1.getDimension(); ++i) {
        std::cout << v1.getKomponente(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Length of v1: " << v1.laenge() << std::endl;

    CMyVektor v2(3);
    v2.setKomponente(0, 4.0);
    v2.setKomponente(1, 5.0);
    v2.setKomponente(2, 6.0);

    CMyVektor v3 = v1 + v2;
    std::cout << "Vector v3 (v1 + v2): ";
    for (int i = 0; i < v3.getDimension(); ++i) {
        std::cout << v3.getKomponente(i) << " ";
    }
    std::cout << std::endl;

    double lambda = 2.0;
    CMyVektor v4 = lambda * v1;
    std::cout << "Vector v4 (lambda * v1): ";
    for (int i = 0; i < v4.getDimension(); ++i) {
        std::cout << v4.getKomponente(i) << " ";
    }
    std::cout << std::endl;
    */

    /*
    //Gradient test
    CMyVektor x1(3);
    x1[0] = 1.0;
    x1[1] = 3.0;
    x1[2] = 2.0;

    CMyVektor gradienttest = gradient(x1, sampleFunction);

    std::cout << "Gradient at x1(" << x1[0] << ", " << x1[1] << ", " << x1[2] << "): ";
    for (int i = 0; i < gradienttest.getDimension(); ++i) {
        std::cout << gradienttest[i] << " ";
    }
    std::cout << std::endl;
    */

    //Funktion f 
    
    CMyVektor x2(2);
    x2.setKomponente(0, 0.2);
    x2.setKomponente(1, -2.1);
    
    CMyVektor a = maximierung(x2, 1, f);
    std::cout << a << std::endl;
    /**/
    /*
    //Funktion g 
    CMyVektor x3(3);
    x3.setKomponente(0, 0);
    x3.setKomponente(1, 0);
    x3.setKomponente(2, 0);

    CMyVektor b = maximierung(x3, 0.1, g);
    std::cout << b << std::endl;
    */

    return 0;

}