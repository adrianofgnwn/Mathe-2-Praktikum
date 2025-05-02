#include "CMyVektor.h"

double CMyVektor::laenge() const {
    double length = 0.0;

    for (double value : komponente) {
            length += pow(value, 2);
    }
    return sqrt(length);
}

CMyVektor operator+(CMyVektor a, CMyVektor b) {
    if (a.dimension != b.dimension) {
        std::cerr << "Fehler: Vektoren mit unterschiedlichen Dimensionen können nicht hinzugefügt werden!" << std::endl;
        return CMyVektor(0); 
    }
    
    CMyVektor result(a.dimension);
    
    for (int i = 0; i < a.dimension; ++i) {
        result.komponente[i] = a.komponente[i] + b.komponente[i];
    }

    return result;
}

CMyVektor operator*(double lambda, CMyVektor a) {
    CMyVektor result(a.dimension);
    
    for (int i = 0; i < a.dimension; ++i) {
        result.komponente[i] = lambda * a.komponente[i];
    }
    
    return result;
}

std::ostream& operator<<(std::ostream& os, CMyVektor vektor) {
    int dimension = vektor.getDimension();
    for (int i = 0; i < dimension; i++) {
        
        if (i == 0) {
            os << "(";
        }
        
        os << vektor[i];
        if (i < dimension - 1) {
            os << "; ";
        }
        
        if (i == dimension - 1) {
            os << ")";
        }
    }
    
    return os;
}


