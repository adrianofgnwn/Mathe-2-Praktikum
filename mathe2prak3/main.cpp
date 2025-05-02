#include <iostream>
#include "CMyVektor.h"
#include "C_DGLSolver.h"

using namespace std;

//1. Ordnnung
CMyVektor f1(CMyVektor y, double x)
{
    CMyVektor y_wert(2);
    y_wert[0] = (2 * y[1]) - (x * y[0]); //y1'
    y_wert[1] = (y[0]*y[1]) - (2 * pow(x, 3)); //y2'

    return y_wert;
}

//3. Ordnung
double fn(CMyVektor y, double x)
{
    return (2 * x * y[1] * y[2]) + (2 * pow(y[0], 2) * y[1]);
}

int main()
{
    //erste Ordnung
    C_DGLSolver test1(f1);
    CMyVektor y1(2);
    test1.print = true;

    
    //Startwerte
    y1[0] = 0;
    y1[1] = 1;

    //x_start = 0, x_end = 2, schritt = 100, h = (2-0)/100 = 0.2
    
    test1.euler_verfahren(0.0, 2.0, 100, y1);
    cout << endl << endl;
    
    /*
    test1.heun_verfahren(0.0, 2.0, 100, y1);
    cout << endl << endl;
    */
    
    //n-ter Ordnung
    C_DGLSolver test2(fn);
    CMyVektor y2(3);
    test2.print = false;

    //Startwerte
    y2[0] = 1;
    y2[1] = -1;
    y2[2] = 2;


    for (int count = 1, schritt = 10; count <= 4; count++, schritt *=10)
    {
        cout << "Abweichung bei Euler-Verfahren bei " << schritt << " Schritten: -" << 0.5 - test2.euler_verfahren(1, 2, schritt, y2)[0] << endl;
        cout << "Abweichung bei Heun-Verfahren bei " << schritt << " Schritten: -" << 0.5 - test2.heun_verfahren(1, 2, schritt, y2)[0] << endl;
    }


    return 0;
}