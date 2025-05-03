#include <iostream>
#include <vector>
#include "CKomplex.h"
#include "math.h"

using namespace std;

int main()
{
    vector<CKomplex> original1, original2, aufgabe5;
    original1 = werte_einlesen("Daten_original1.txt");
    original2 = werte_einlesen("Daten_original2.txt");
    aufgabe5 = werte_einlesen("aufgabe5.txt");

    vector<CKomplex> hin1 = fourier_trafo(original1, true);
    vector<CKomplex> hin2 = fourier_trafo(original2, true);
    vector<CKomplex> aufgabe5_hin = fourier_trafo(aufgabe5, true);

    //hin1  
    werte_ausgeben("Daten_fourier_trafo_hin1_standard.txt", hin1);
    werte_ausgeben("Daten_fourier_trafo_hin1_0.001.txt", hin1, 0.001);
    werte_ausgeben("Daten_fourier_trafo_hin1_0.01.txt", hin1, 0.01);
    werte_ausgeben("Daten_fourier_trafo_hin1_0.1.txt", hin1, 0.1);
    werte_ausgeben("Daten_fourier_trafo_hin1_1.0.txt", hin1, 1.0);

    //hin2
    werte_ausgeben("Daten_fourier_trafo_hin2_standard.txt", hin2);
    werte_ausgeben("Daten_fourier_trafo_hin2_0.001.txt", hin2, 0.001);
    werte_ausgeben("Daten_fourier_trafo_hin2_0.01.txt", hin2, 0.01);
    werte_ausgeben("Daten_fourier_trafo_hin2_0.1.txt", hin2, 0.1);
    werte_ausgeben("Daten_fourier_trafo_hin2_1.0.txt", hin2, 1.0);

    //hinaufgabe5
    werte_ausgeben("aufgabe5_hin_aufgabe5_10.txt", aufgabe5_hin, 10);
    werte_ausgeben("aufgabe5_hin_aufgabe5_30.txt", aufgabe5_hin, 30);
    werte_ausgeben("aufgabe5_hin_aufgabe5_100.txt", aufgabe5_hin, 100);
    werte_ausgeben("aufgabe5_hin_aufgabe5_300.txt", aufgabe5_hin, 300);

    vector<CKomplex> rueck1_1, rueck1_2, rueck1_3, rueck1_4, rueck1_5;
    vector<CKomplex> rueck2_1, rueck2_2, rueck2_3, rueck2_4, rueck2_5;
    vector<CKomplex> aufgabe5_rueck_1, aufgabe5_rueck_2, aufgabe5_rueck_3, aufgabe5_rueck_4;

    //hin1
    rueck1_1 = werte_einlesen("Daten_fourier_trafo_hin1_standard.txt");
    rueck1_2 = werte_einlesen("Daten_fourier_trafo_hin1_0.001.txt");
    rueck1_3 = werte_einlesen("Daten_fourier_trafo_hin1_0.01.txt");
    rueck1_4 = werte_einlesen("Daten_fourier_trafo_hin1_0.1.txt");
    rueck1_5 = werte_einlesen("Daten_fourier_trafo_hin1_1.0.txt");
    
    //hin2
    rueck2_1 = werte_einlesen("Daten_fourier_trafo_hin2_standard.txt");
    rueck2_2 = werte_einlesen("Daten_fourier_trafo_hin2_0.001.txt");
    rueck2_3 = werte_einlesen("Daten_fourier_trafo_hin2_0.01.txt");
    rueck2_4 = werte_einlesen("Daten_fourier_trafo_hin2_0.1.txt");
    rueck2_5 = werte_einlesen("Daten_fourier_trafo_hin2_1.0.txt");


    aufgabe5_rueck_1 = werte_einlesen("aufgabe5_hin_aufgabe5_10.txt");
    aufgabe5_rueck_2 = werte_einlesen("aufgabe5_hin_aufgabe5_30.txt");
    aufgabe5_rueck_3 = werte_einlesen("aufgabe5_hin_aufgabe5_100.txt");
    aufgabe5_rueck_4 = werte_einlesen("aufgabe5_hin_aufgabe5_300.txt");


    //Fourier_Rück_Transformation          
    vector<CKomplex> a1 = fourier_trafo(rueck1_1, false),
                     a2 = fourier_trafo(rueck1_2, false),
                     a3 = fourier_trafo(rueck1_3, false),
                     a4 = fourier_trafo(rueck1_4, false),
                     a5 = fourier_trafo(rueck1_5, false);

    vector<CKomplex> b1 = fourier_trafo(rueck2_1, false),
                     b2 = fourier_trafo(rueck2_2, false),
                     b3 = fourier_trafo(rueck2_3, false),
                     b4 = fourier_trafo(rueck2_4, false),
                     b5 = fourier_trafo(rueck2_5, false);
    
    vector<CKomplex> c1 = fourier_trafo(aufgabe5_rueck_1, false),
                     c2 = fourier_trafo(aufgabe5_rueck_2, false),
                     c3 = fourier_trafo(aufgabe5_rueck_3, false),
                     c4 = fourier_trafo(aufgabe5_rueck_4, false);

    werte_ausgeben("aufgabe5_rueck_aufgabe5_10.txt", c1);
    werte_ausgeben("aufgabe5_rueck_aufgabe5_30.txt", c2);
    werte_ausgeben("aufgabe5_rueck_aufgabe5_100.txt", c3);
    werte_ausgeben("aufgabe5_rueck_aufgabe5_300.txt", c4);

    //rueck1 und original1
    cout << "Bei Daten_original1.txt" << endl;
    abweichung(a1, original1, -1.0);
    abweichung(a2, original1, 0.001);
    abweichung(a3, original1, 0.01);
    abweichung(a4, original1, 0.1);
    abweichung(a5, original1, 1.0);

    cout << endl;

    cout << "Bei Daten_original2.txt" << endl;
    abweichung(b1, original2, -1.0);
    abweichung(b2, original2, 0.001);
    abweichung(b3, original2, 0.01);
    abweichung(b4, original2, 0.1);
    abweichung(b5, original2, 1.0);

    return 0;

}
