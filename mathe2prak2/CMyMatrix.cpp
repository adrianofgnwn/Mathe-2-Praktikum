#include "CMyMatrix.h"
#include <exception>
#include <iostream>

using namespace std;

CMyMatrix::CMyMatrix(int row, int column) : row(row), column(column) {
    komponente.resize(row); 

    for (int i = 0; i < row; i++) {
        komponente[i].resize(column);
    }
}

CMyVektor operator* (CMyMatrix a, CMyVektor b) {
    //col of matrix must be equal to the dimension of vector
    if (a.getColumn() != b.getDimension()) {
        cout << "Keine Multiplikation möglich!" << endl
             << " Die Anzahl der Spalten vom Matrix ist ungleich die Anzahl des Dimensions vom Vektor" << endl;
        exit(1);
        //row = zeile, column = spalte
    }
    
    CMyVektor m(a.getRow());

    for (int i = 0; i < a.getRow(); i++) {
        for (int j = 0; j < a.getColumn(); j++) {
            m[i] += a[i][j] * b[j]; 
        }
    }      

    return m;
}

CMyMatrix CMyMatrix::invers() {
    //if not 2x2 = error
    if (row != 2 || column != 2) {
        cout << "Matrix ist kein 2x2 Matrix" << endl;
        exit(1);
    
    } else {
        //det = ad - bc
        double determinan = komponente[0][0]*komponente[1][1] - komponente[0][1]*komponente[1][0];

        if (determinan == 0) {
            cout << "Die Determinante ist 0." << endl;
            exit(1);
        }
        
        CMyMatrix inversergebnis(2,2); //matrix 2x2
        //set inverse position
        inversergebnis[0][0] = komponente[1][1] * 1/determinan;
        inversergebnis[1][1] = komponente[0][0] * 1/determinan;
        inversergebnis[0][1] = -komponente[0][1] * 1/determinan;
        inversergebnis[1][0] = -komponente[1][0] * 1/determinan;

        return inversergebnis;
    }
}

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x)) {

    const double h = 1e-4;
    CMyVektor fx = funktion(x);
    CMyMatrix jacobs(fx.getDimension(), x.getDimension());

    for (int i = 0; i < jacobs.getRow(); i++) {
        for (int j = 0; j < jacobs.getColumn(); j++) {
            CMyVektor x_plus_h = x;
            x_plus_h[j] += h;
            jacobs[i][j] = (funktion(x_plus_h)[i] - fx[i]) / h;
        }
    }
    
    return jacobs;
}

CMyVektor NewtonVerfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor x)) {
    for (int count = 0; count < 50 ; count++) {
        CMyMatrix jacobs = jacobi(x, funktion);
        CMyMatrix invers_matrix = jacobs.invers();
        CMyVektor delta_x = -1 * (invers_matrix * funktion(x));

        if (funktion(x).laenge() < 1e-5) {
            cout << "Ende wegen ||f(x)|| < 1e-5 bei: " << endl
                 << "\t x =" << x << endl;
            cout << "\t f(x) = " << funktion(x) << endl;
            cout << "\t ||f(x)|| = " << funktion(x).laenge() << endl << endl;
            break;
        }

        if (count == 50) {
            cout << "Ende wegen Schrittanzahl = 50 bei: " << endl
                 << "\t x =" << x << endl;
            cout << "\t f(x) = " << funktion(x) << endl;
            cout << "\t ||f(x)|| = " << funktion(x).laenge() << endl << endl;
            break;
        }
        
        cout << "Schritt " << count << ": " << endl;
        cout << "\t x = " << x << endl;
        cout << "\t f(x) = " << funktion(x) << endl;
        cout << "\t f'(x) = " << endl << jacobs;
        cout << "\t (f'(x))^(-1) = " << endl << invers_matrix;
        cout << "\t dx = " << delta_x << endl;
        cout << "\t ||f(x)|| = " << funktion(x).laenge() << endl << endl;

        x = x + delta_x;
    }

    return x;
}

vector<double>& CMyMatrix::operator[](int index) {
    if (index < 0 || index >= column) {
        cout << "Index is out of range." << endl;
        exit(1);
    }
    
    return komponente[index];
}

ostream& operator<< (ostream& stream, const CMyMatrix& m) {
    
    for (int i = 0; i < m.row ; i++) {
        stream << "\t \t"; 
        if(i ==0) {
            cout << "( ";}

        for (int j = 0; j < m.column; j++) {
            if(j == m.column - 1) {
                stream << m.komponente[i][j];
            } else {
                stream << m.komponente[i][j] << "; ";
            }
        }

        if(i == m.row - 1){
            cout << " )" << endl;
        } else {
            cout << endl;
        }
        
    }
    return stream;
}

