#pragma once 

#include "CZufall.h"
#include <vector>

class CLotto
{
private:
    int k, n; // k-aus-n Lotto
    int s; // initialisation variable

    std::vector<int> tippzettel; //richtige Kombination
    CZufall zufall; //Zufallwerte

public:
    CLotto(int _k, int _n, int _s); //konstruktor
    
    void set_tippzettel(std::vector<int> tippzettel); //setter

    std::vector<int> ziehen(); //zieht k-aus-n Zufallwerte ohne zurücklegen

    int ziehen_true(); //anzahl der übereinstimmende Zahl


};


