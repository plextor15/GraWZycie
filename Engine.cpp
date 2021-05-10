#include "Engine.h"
//#include <fstream>

Engine::Engine(){

}

Engine::~Engine(){

}

void Engine::Initialize(){
    long szerokosc, wysokosc;

    std::ifstream inic;
    inic.open("plansza.ini");
    inic >> szerokosc >> wysokosc;
    SetSzerokosc(szerokosc);
    SetWysokosc(wysokosc);

    *Plansza = new Cell[GetWysokosc()];
    for (long i = 0; i < GetWysokosc(); i++){
        Plansza[i] = new Cell[GetSzerokosc()];
    }

    long ileWszystkich = GetSzerokosc() * GetWysokosc(); //ile jest wszystkich pol na planszy
    bool czytnik;
    for (long i = 0; i < ileWszystkich; i++){
        inic >> czytnik;
        if (czytnik) {
            Plansza[ileWszystkich / GetWysokosc()][ileWszystkich / GetSzerokosc()].Ozyw();
        }
        //else { //wszystkie zaczynaja jako martwe
        //    Plansza[ileWszystkich / GetWysokosc()][ileWszystkich / GetSzerokosc()].Zabij();
        //}
    }

    inic.close();
    return;
}

void Engine::GameLoop(){
    while (true)
    {
        Analiza();
        Przejscie();
    }

    return;
}


