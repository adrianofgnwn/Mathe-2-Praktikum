#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "CZufall.h"

using namespace std;

//liefert ein Wert zwischen a und b
int CZufall::wert(int a, int b)
{
    return a + rand() %(b - a+1);
}

//initialisiert den Zufallszahlengenerator mit dem Seed s unter Verwendung von srand().
void CZufall::initialisiere(int s)
{
    srand(s);
}

void CZufall::test(int a, int b, int N)
{
    vector<int> h(b - a+1, 0);

    //Zufall
    for (int i = 0; i < N; i++)
    {
        h[wert(a, b) - a]++;
    }

    //Ausgabe
    for (int i = a; i <= b; i++)
    {
        cout << i << " : " << h[i - a] << endl;
    }
        
}

//aehnlich wie test(), aber der Generator wird jedes Mal neu initialisiert
void CZufall::test_falsch(int a, int b, int N)
{
    vector<int> h(b - a+1, 0);

    //Zufall
    for (int i = 0; i < N; i++)
    {
        initialisiere(time(NULL));
        h[wert(a, b) - a]++;
    }
    
    //Ausgabe
    for (int i = a; i <= b; i++)
    {
        cout << i << " : " << h[i - a] << endl;
    }
    
}
