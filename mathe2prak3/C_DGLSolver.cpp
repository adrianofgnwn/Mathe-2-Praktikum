#include "C_DGLSolver.h"
#include <iostream>

using namespace std;

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x)
{
    //Prüft ob es nterOrdnung
    if (nterOrdnung)
    {
        //Vektor zum Speichern
        CMyVektor Ableitung(y.get_dimension());

        //Rechts scheiben
        for (int i = 0; i < y.get_dimension() - 1; i++) // für jede Ordnung
        {
            Ableitung[i] = y[i+1];
        }

        //Letzte index
        Ableitung[y.get_dimension() - 1] = f_DGL_nterOrdnung(y, x); // n-te Ordnung geben

        return Ableitung;
    }
    
    else 
    {
        return f_DGL_System(y, x);
    }
}

CMyVektor C_DGLSolver::euler_verfahren(double x_start, double x_end, double schritt, CMyVektor y_start)
{
    CMyVektor y_wert; 
    y_wert = y_start;

 
    double h = (x_end - x_start) / schritt; 

    if (print)
    {
        cout << "h = " << h << endl << endl;

        
    }
    
    for (int i = 0; i <= schritt; i++)
        {
            if (i == schritt)
            {
                if (print)
                {
                    cout << "Ende bei: " << endl
                         << "\t x= " << x_start << endl
                         << "\t y= " << y_wert << endl;
                }
                
                break;
            }
            else
            {
                if (print)
                {
                    cout << "Schritt " << i << ": " << endl
                         << "\t x = " << x_start << endl
                         << "\t y = " << y_wert << endl
                         << "\t y' = " << ableitungen(y_wert, x_start) << endl; 
                }

                //Euler Formel
                y_wert = y_wert + (h * ableitungen(y_wert, x_start)); //Formel Euler
                //X wert aktualisieren
                x_start = x_start + h;
                
            }
            
        }       
        return y_wert;
}

CMyVektor C_DGLSolver::heun_verfahren(double x_start, double x_end, double schritt, CMyVektor y_start)
{
    CMyVektor y_wert, euler_schritt, mittel_ableitung;
    y_wert = y_start;

    double h = (x_end - x_start) / schritt;

    if (print)
    {
        cout << "h = " << h << endl << endl;
    }

    for (int i = 0; i <= schritt; i++)
    {
        if (i == schritt)
        {
            if (print)
            {
                cout << "Ende bei: " << endl
                 << "\t x = " << x_start << endl
                 << "\t y = " << y_wert << endl;
            }
            
            break;
        }
        
        if (print)
        {
            cout << "Schritt: " << i << ": " << endl
                 << "\t x = " << x_start << endl
                 << "\t y = " << y_wert << endl
                 << "\t y'_ori = " << ableitungen(y_wert, x_start) << endl;
        }
        //Euler Formel
        euler_schritt = y_wert + (h * ableitungen(y_wert, x_start));

        if (print)
        {
            cout << "\t y_test = " << euler_schritt << endl
                 << "\t y'_test = " << ableitungen(euler_schritt, (x_start + h)) << endl;
        }
        //Mittel Ableitung Formel
        mittel_ableitung = 0.5 * (ableitungen(y_wert, x_start) + ableitungen(euler_schritt, (x_start + h)));

        if (print)
        {
            cout << "\t y'_mittel = " << mittel_ableitung << endl;
        }

        //Heun Formel
        y_wert = y_wert + (h * mittel_ableitung); //Formel Heun-Verfahren
        //X wert aktualisieren
        x_start = x_start + h;
        
        if (print)
        {
            cout << endl << endl;
        }
        
        
    }

    return y_wert;

}