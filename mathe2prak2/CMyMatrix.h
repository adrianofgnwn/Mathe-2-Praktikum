#include <iostream>
#include <vector>
#include <math.h>
#include "CMyVektor.h"

using namespace std; 

class CMyMatrix
{
private:
    vector<vector<double>> komponente; //2D, zeile und spalte
    int row, column; //row = zeile, column = spalte

public:
    //Konstruktor
    CMyMatrix(int row, int column);

    //Getter
    int getRow() const {return row;}

    int getColumn() const {return column;}

    double getKomponente(int c, int r) const {return komponente[c][r];}

    //Setter
    void setKomponente(int c, int r, double value) {komponente[c][r] = value;}

    //Operator
    vector<double>& operator[](int index);

    friend CMyVektor operator*(CMyMatrix a, CMyVektor b); //2x2 Matrix * Vector

    friend ostream& operator<<(ostream& stream, const CMyMatrix& m);

    //Invers
    CMyMatrix invers();
};

CMyMatrix jacobi(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));

CMyVektor NewtonVerfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor x));
