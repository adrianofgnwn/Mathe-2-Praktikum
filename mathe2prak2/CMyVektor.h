#pragma once
#include <iostream>
#include <vector>
#include <cmath>

class CMyVektor {
private:
    std::vector<double> komponente;
    int dimension;

public:
    //Konstruktor
    CMyVektor(int dim) : dimension{dim} {
        komponente.resize(dim);
    }

    //Setters und Getters
    int getDimension() const {
        return dimension;
    }

    void setKomponente(int index, double value) {
        komponente[index] = value;
    }

    double getKomponente(int index) const {
        return komponente[index];
    }

    double laenge() const;

    friend CMyVektor operator+(CMyVektor a, CMyVektor b);

    friend CMyVektor operator*(double lambda, CMyVektor a);

    friend std::ostream& operator<<(std::ostream& os, CMyVektor vektor);

    double& operator[](int index) {
        return komponente[index];
    }

};
