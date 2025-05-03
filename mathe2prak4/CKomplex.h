#include <iostream>
#include <vector>
#include <math.h>

// Aufgabe 1
class CKomplex
{
private:
    double real, imag;

public:
    CKomplex();
    CKomplex(double a, double b); // Darstellung a+bj
    CKomplex(double phi); // Darstellung e^j.phi

    double re() const;
    double im() const;
    double abs() const; // gibt den Betrag der komplexen Zahlen zurück

    friend CKomplex operator+(const CKomplex& komplex1, const CKomplex& komplex2); // komplex1 + komplex2
    friend CKomplex operator*(const CKomplex& komplex1, const CKomplex& komplex2); // komplex1 * komplex2
    friend CKomplex operator*(const CKomplex& komplex, double lambda); // zahl * komplexe Zahl

    
};

// Aufgabe 2
// Vektoren aus komplexen Zahlen aus einer .txt
std::vector<CKomplex> werte_einlesen(const std::string dateiname); // einlesen
void werte_ausgeben(const std::string dateiname, std::vector<CKomplex> werte, double epsilon =-1); // ausgeben

// Aufgabe 3
std::vector<CKomplex> fourier_trafo(std::vector<CKomplex> vektor, bool hin);


// Aufgabe 4
void abweichung(std::vector<CKomplex> rueck_wert, std::vector<CKomplex> ori_wert, double epsilon); // Maximale Abweichung
