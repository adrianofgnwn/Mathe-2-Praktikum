#include "CZufall.h"
#include "CLotto.h"
#include <iostream>

using namespace std;

void test_aufgabe()
{
    cout << "Die Testaufgabe faeng an:" << endl << endl;
    //a) gleiche Wert von s
    cout << "Aufgabe a) " << endl;
    CZufall zufall;

    for (int i = 0; i < 3; i++)
    {
        zufall.initialisiere(0);
        zufall.test(3, 7, 10000);
        cout << "------------------------------------------" << endl;
    }
    cout << endl;
    
    //b) Verschiedene Wert von s
    cout << "Aufgabe b) " << endl;
    for (int i = 0; i < 3; i++)
    {
        zufall.initialisiere(i);
        zufall.test(3, 7, 10000);
        cout << "------------------------------------------" << endl;
    }
    cout << endl;

    //c) s = time(NULL)
    cout << "Aufgabe c) " << endl;
    for (int i = 0; i < 3; i++)
    {
        zufall.initialisiere(time(NULL));
        zufall.test(3, 7, 10000);
        cout << "------------------------------------------" << endl;
    }
    cout << endl;

    //d) 
    cout << "Aufgabe d) " << endl;
    zufall.test_falsch(3, 7, 10000);
    cout << endl;
}

void Monte_Carlo_Simulation(int k, int n, int r, int N, int Typ)
{
    CLotto lotto(k, n, -1);

    int nk = 0;
    vector<int> tippzettel;

    //immer den gleichen Typ
    if (Typ == 1)
    {
        tippzettel = lotto.ziehen();
        lotto.set_tippzettel(tippzettel); 

        for (int i = 0; i < N; i++)
        {
            if (lotto.ziehen_true() == r)
            {
                nk++;
            }
        }
    }
    
    //verschiedenen Typ jedes mal
    else if (Typ == 2)
    {
        for (int i = 0; i < N; i++)
        {
            tippzettel = lotto.ziehen();
            lotto.set_tippzettel(tippzettel);

            if (lotto.ziehen_true() == r)
            {
                nk++;
            }
            
        }
        
    }
    
    cout << "Monte-Carlo-Simulation von Spieler " << Typ << " fuer " << k << "-aus-" << n
        << " Lotto mit genau " << r << " Richtige: W' betraegt " << nk * 100.0 / N << "%" << endl << endl;
}

int main() 
{
    test_aufgabe();

    cout << "Beginn der Monte-Carlo-Simulation . . . " << endl;
    Monte_Carlo_Simulation(6, 34, 3, 1e6, 1);
    Monte_Carlo_Simulation(6, 34, 3, 1e6, 2);
}