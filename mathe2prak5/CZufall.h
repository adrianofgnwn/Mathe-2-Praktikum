#pragma once

class CZufall
{

public:
    int wert(int a, int b); //liefert Zufallszahl n zwischen a und b
    void initialisiere(int s); //inisialisiert Zufallsgenerator mit srand()
    void test(int a, int b, int N); //zieht N mal eine Zufallszahl zwischen a und b, ohne neue Initialisierung
    void test_falsch(int a, int b, int N); // wie test, mit neuen Initialisierung von time(NULL)
};
