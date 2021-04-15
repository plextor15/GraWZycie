#include "Engine.h"

Engine::Engine(){
}

Engine::~Engine(){
    //destrukcja tablic
    if (Plansza) {
        for (long i = 0; i < Wysokosc; i++) {
            delete[] Plansza[i];
        }
        delete[] Plansza;
        Plansza = NULL;
    }

    if (PlanszaTMP) {
        for (long i = 0; i < Wysokosc; i++) {
            delete[] PlanszaTMP[i];
        }
        delete[] PlanszaTMP;
        PlanszaTMP = NULL;
    }
}

void Engine::Initialize(){
    long szerokosc, wysokosc;

    std::ifstream inic;
    inic.open("plansza.ini");
    inic >> szerokosc >> wysokosc;
    Szerokosc = szerokosc;
    Wysokosc = wysokosc;

    Plansza = new Cell*[Wysokosc];
    for (long i = 0; i < Wysokosc; i++){
        Plansza[i] = new Cell[Szerokosc];
    }

    //stworzenie PlanszaTMP zeby byla, pozniej tylko zerowanie
    PlanszaTMP = new Cell * [Wysokosc];
    for (long i = 0; i < Wysokosc; i++) {
        PlanszaTMP[i] = new Cell[Szerokosc];
    }

    bool bx;
	for (long i = 0; i < Wysokosc; i++){
		for (long j = 0; j < Szerokosc; j++){
            inic >> bx;
			Plansza[i][j].SetCell(bx);
		}
	}

    inic.close();
    return;
}

void Engine::Przejscie() {
    for (long i = 0; i < Wysokosc; i++) {
        for (long j = 0; j < Szerokosc; j++) {
            Plansza[i][j] = PlanszaTMP[i][j];
        }
    }

    return;
}

void Engine::GameLoop(){
    Initialize();
    while (true) {
        Analiza();
        Przejscie();
        View();
    }

    return;
}