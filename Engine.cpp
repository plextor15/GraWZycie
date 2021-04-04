#include "Engine.h"
#include <fstream>

Engine::Engine(){
    Array Plansza();

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
}
