#pragma once

#include "CMyVektor.h"
#include <iostream>

class  C_DGLSolver
{
private:
    CMyVektor(*f_DGL_System)(CMyVektor y, double x); //Funktionspointer für erste Ordnung
    double(*f_DGL_nterOrdnung)(CMyVektor y, double x); //Funktionspointer für n-te Ordnung
    bool nterOrdnung; //Indikator dafür, mit welchem ​​DGL-System wir es zu tun haben
    CMyVektor ableitungen(CMyVektor y, double x); //Transform DGL n-te Ordnung zu DGL erste Ordnung

public:
    //- - - - - - - - - - - -Konstruktoren- - - - - - - - - - - -
    //erste Ordnung DGL System
    C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x)) :
        f_DGL_System(f_DGL_System),
        nterOrdnung(false),
        print(false){}
    
    //nter Ordnung DGL System
    C_DGLSolver(double(*f_DGL_nterOrdnung)(CMyVektor y, double x)) :
        f_DGL_nterOrdnung(f_DGL_nterOrdnung),
        nterOrdnung(true),
        print(false) {}
    
    //- - - - - - - - - - - -Methoden- - - - - - - - - - - -
    bool print;
    CMyVektor euler_verfahren(double x_start, double x_end, double schritt, CMyVektor y_start);
    CMyVektor heun_verfahren(double x_start, double x_end, double schritt, CMyVektor y_start);


    
};
