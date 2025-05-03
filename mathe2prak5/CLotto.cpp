#include "CLotto.h"
#include <iostream>

using namespace std;

CLotto::CLotto(int _k, int _n, int _s) : k{_k}, n{_n}
{
    if (s < 0)
    {
        s = time(NULL);
    }
    else
    {
        s = _s;
    }
    
    zufall.initialisiere(s);
}

void CLotto::set_tippzettel(vector<int> _tippzettel)
{
    tippzettel = _tippzettel;
}

//prueft ob ein Zahl, schon in der Vektor ist
bool result(vector<int>& v, int zahl)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == zahl)
        {
            return true;
        }
    }
    return false;
    
}

//ziehen
vector<int> CLotto::ziehen()
{
    //zahlen speichern
    vector<int> ziehung;
    int Zufallszahl = 0;

    for (int i = 0; i < k; i++)
    {
        do
        {
            Zufallszahl = zufall.wert(1, n);
        } while (result(ziehung, Zufallszahl));
        
        ziehung.push_back(Zufallszahl);
    }

    return ziehung;
}

//vergleichen
int CLotto::ziehen_true()
{
    vector<int> ziehung = ziehen();
    int richtig = 0;

    for (int zahl : ziehung)
    {
        if (result(tippzettel, zahl))
        {
            richtig++;
        }
        
    }
    
    return richtig;
}