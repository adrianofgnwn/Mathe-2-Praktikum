#pragma once
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class CMyVektor
{
private:
    vector<double> vec;
    int dimension;

public:
    CMyVektor();
    CMyVektor(int dimensions);

    int get_dimension()
    {
        return dimension;
    }

    double get_length();

    friend ostream& operator<<(ostream& stream, const CMyVektor& v);

    double& operator[](int index);

    friend CMyVektor operator+(CMyVektor a, CMyVektor b);
    friend CMyVektor operator*(double lambda, CMyVektor a);

};

