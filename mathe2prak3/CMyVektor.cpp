#include "CMyVektor.h"
#include <iostream>

using namespace std;

CMyVektor::CMyVektor() {} //Standardkonstuktor

CMyVektor::CMyVektor(int dimensions) : dimension(dimensions)
{
    vec.resize(dimensions);
}

double CMyVektor::get_length() 
{
    double sum = 0; 

    for (int i = 0; i < get_dimension(); i++)
    {
        sum += vec[i]*vec[i];
    }

    return sqrt(sum);
}

double& CMyVektor::operator[](int index)
{
    if (index < 0 || index >= get_dimension())
    {
        cout << "Index is out of range." << endl;
        exit(1);
    }
    
    return vec[index];
}

CMyVektor operator+(CMyVektor a, CMyVektor b)
{
    if (a.get_dimension() != b.get_dimension())
    {
        throw "Die zu addierenden Vektoren befinden sich in verschiedlichen Dimensionen";
        return CMyVektor(0); 
    }

    CMyVektor newVector(a.get_dimension());

    for (int i = 0; i < a.get_dimension(); i++)
    {
        newVector[i] = a[i] + b[i];
    }
    
    return newVector;
}

CMyVektor operator*(double lambda, CMyVektor a)
{
    CMyVektor newVector(a.get_dimension());
    for (int i = 0; i < a.get_dimension(); i++)
    {
        newVector[i] = lambda * a[i];
    }
    
    return newVector;
}

ostream& operator<<(ostream& output, const CMyVektor& v)
{
    output << "(";

    for (const double& value : v.vec)
    {
        output << value << " ";
    }
    
    output << ")";
    
    return output;
}

