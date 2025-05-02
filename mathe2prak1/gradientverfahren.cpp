#include "gradientverfahren.h"
#include <cmath>
using namespace std;

CMyVektor maximierung(CMyVektor x0, double lambda, double(*funktion)(CMyVektor x)) {
    double g = gradient(x0, funktion).laenge();
    int schritte = -1;

    CMyVektor x(x0.getDimension());
    CMyVektor x_test(x0.getDimension());

    x = x0;

    bool halbieren = false;
    while (g >= 1e-5 && schritte != 25) {
        halbieren = false;
        g = gradient(x0, funktion).laenge();
        schritte++;

        if (g < 1e-5 || schritte == 25) {
            if (g < 1e-5) {
                cout << "Ende wegen ||grad f(x)|| < 1e-5 bei " << endl;
            }
            
            if (schritte == 25) {
                cout << "Ende wegen Schrittanzahl = 25 bei " << endl; 
            }  
        
        } else {
            cout << "Schritt " << schritte << ": " << endl;
        }
        
        x = x0 + lambda * gradient(x0, funktion);
        
        cout << "\t x = " << x0 << endl;
        cout << "\t lambda = " << lambda << endl;
        cout << "\t f(x) = " << funktion(x0) << endl;

        cout << "\t grad f(x) = " << gradient(x0,funktion) << endl;
        cout << "\t ||grad f(x)|| = " << g << endl << endl;

        if (g < 1e-5 || schritte == 25) {
            break;
        }

        cout << "\t x_neu = " << x << endl;
        cout << "\t f(x_neu) = " << funktion(x) << endl << endl;

        while (funktion(x) <= funktion(x0)) {
            halbieren = true;
            cout << "\t Schrittweite halbieren (lambda = " << lambda/2 << "): " << endl;
            lambda *= 0.5;
            x = x0 + lambda * gradient(x0, funktion);

            cout << "\t x_neu = " << x << endl;
            cout << "\t f(x_neu) = " << funktion(x) << endl << endl;

        }
        
        if (halbieren) {
            x0 = x;
            continue;
        }
        
        cout << "\t Test mit doppelter Schrittweite (lambda = " << 2 * lambda << "): " << endl;
        x_test = x0 + (2 * lambda) * gradient(x0, funktion);

        cout << "\t x_test = " << x_test << endl;
        cout << "\t f(x_test) = " << funktion(x_test) << endl;

        if (funktion(x_test) > funktion(x)) {
            lambda *= 2;
            x0 = x_test;
            cout << "\t verdoppelte Schrittweite!" << endl << endl;
        
        } else {
            cout << "\t behalte alte Schrittweite!" << endl << endl;
            x0 = x;
        }
        

    }
    
    return x0;
}
