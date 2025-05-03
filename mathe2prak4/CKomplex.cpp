#include "CKomplex.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Aufgabe 1
CKomplex::CKomplex()
{
    //0 + 0*j
    this->real = 0;
    this->imag = 0;
}

CKomplex::CKomplex(double a, double b)
{
    //a + b*j
    this->real = a;
    this->imag = b;
}

CKomplex::CKomplex(double phi)
{
    //e^j*phi = cos(phi) + j*sin(phi)
    this->real = cos(phi);
    this->imag = sin(phi);
}
double CKomplex::re() const
{
    return real;
}

double CKomplex::im() const
{
    return imag;
}

//Betrag
double CKomplex::abs() const
{
    return sqrt(real*real + imag*imag); //Länge der komplexe Zahlen
}

//Addition
CKomplex operator+(const CKomplex& komplex1, const CKomplex& komplex2)
{
    double result_real, result_imag;
    result_real = komplex1.real + komplex2.real;
    result_imag = komplex1.imag + komplex2.imag;

    CKomplex result(result_real, result_imag);
    return result;
}

//Multiplikation zwischen komplexe Zahlen
CKomplex operator*(const CKomplex& komplex1, const CKomplex& komplex2)
{
    double result_real, result_imag;
    result_real = (komplex1.real * komplex2.real) - (komplex1.imag * komplex2.imag);
    result_imag = (komplex1.real * komplex2.imag) + (komplex1.imag * komplex2.real);

    CKomplex result(result_real, result_imag);
    return result;
}

//Multiplikation mit lambda
CKomplex operator*(const CKomplex& komplex, double lambda)
{
    double result_real, result_imag;

    result_real = komplex.real * lambda;
    result_imag = komplex.imag * lambda;

    CKomplex result(result_real, result_imag);
    return result;
}


//Aufgabe 2
vector<CKomplex> werte_einlesen(const std::string dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
		// File oeffnen
	ifstream fp;
	fp.open(dateiname);
		// Dimension einlesen
	fp >> N;
		// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0,0);
	for (i = 0; i<N; i++)
		werte[i] = null;
		// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re,im);
		werte[idx] = a;
	}
		// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const std::string dateiname, vector<CKomplex> werte, double epsilon)
{
	int i;
	int N = werte.size();
		// File oeffnen
	ofstream fp;
	fp.open(dateiname);
		// Dimension in das File schreiben
	fp << N << endl;
		// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << endl;
		// File schliessen
	fp.close();
}

//Aufgabe 3
//Fourier-Hin_Rueck_Trafo
vector<CKomplex> fourier_trafo(vector<CKomplex> vektor, bool hin)
{
    double N = vektor.size(); //Anzahl der Datenpunkte
    double vorFaktor =  (1 / sqrt(N));

    vector<CKomplex> result(N); //Vektor anlegen

    for (int n = 0; n < N; n++)
    {
        CKomplex summe(0,0); // 0 + 0*j

        for (int k = 0; k < N; k++)
        {
            CKomplex e;
            if (hin == true)
            {
                e = CKomplex(-( (2* M_PI) * k * n) / N); //mit "-"
            }
            else
            {
                e = CKomplex(((2* M_PI) * k * n) / N);// ohne "-"
            }

            summe = summe + vektor[k] * e;
        }

        result[n] = summe * vorFaktor; //Fourierkoeffizienten werden im Vektor c gespeichert
    }
    
    return result;
}

//Abweichung berechnen
void abweichung(vector<CKomplex> rueck_wert, vector <CKomplex> ori_wert, double epsilon)
{
    double abweichung = 0;
    double max_abweichung = -1;

    for (int i = 0; i < ori_wert.size(); i++)
    {
        abweichung = (rueck_wert[i] + ori_wert[i]*(-1)).abs();

        //Max abweichung aktualisieren
        if (abweichung > max_abweichung)
        {
            max_abweichung = abweichung;
        }
        
    }
    
    cout << "Maximale Abweichung bei Epsilon = " << epsilon << ": " << max_abweichung << endl;

}
