#include <iostream>                  //???
using namespace std;                 //???

#include "Engine.h"
//#include <fstream>

Engine::Engine(){

}

Engine::~Engine(){

}

void Engine::Initialize(){
    long szerokosc, wysokosc;

    std::ifstream inic;
cout<<"Init - przed otwarciem pliku\n";                               //???
    inic.open("plansza.ini");
    inic >> szerokosc >> wysokosc;
cout<<"Init - po otwarciu pliku\n"<< szerokosc <<"   "<< wysokosc<<endl;                       //???
    Szerokosc = szerokosc;
    Wysokosc = wysokosc;

//    *Plansza = new Cell[GetWysokosc()];                    //???   --->
//    for (long i = 0; i < GetWysokosc(); i++){
//        Plansza[i] = new Cell[GetSzerokosc()];
//    }


    Plansza = new Cell*[Wysokosc];
    for (long i = 0; i < Wysokosc; i++){
        Plansza[i] = new Cell[Szerokosc];
    }                                                        //???   <---

    //stworzenie PlanszaTMP zeby byla, pozniej tylko zerowanie
    PlanszaTMP = new Cell * [Wysokosc];
    for (long i = 0; i < Wysokosc; i++) {
        PlanszaTMP[i] = new Cell[Szerokosc];
    }



//???  <---
/*   //???  ---> wylaczylem JM  - bardzo skomplikowane;
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
*/   //???  <--- wylaczylem JM
//???  --->    spr. - zamiast linii 44-54 ponizsy tekst;
    bool bx;
	for (long i = 0; i < Wysokosc; i++){
		for (long j = 0; j < Szerokosc; j++){
            inic >> bx;
			Plansza[i][j].SetCell(bx);
		}
	}
//???  <---

    inic.close();

//???  --->    spr.
cout<<"\nPlansza po Init\n";
	for (long i = 0; i < Wysokosc; i++){
		for (long j = 0; j < Szerokosc; j++){
			cout<< Plansza[i][j].GetCell()<<" ";
		}
		cout<<endl;
	}
//???  <---
//??? zbedne;    return;
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
    while (true)
    {
        cout << "\n----------- x: " << Szerokosc << " ,y: " << Wysokosc << " ------------\n";
        system("PAUSE");

        Analiza();
//???        Przejscie();          //??? albo Przejscie() albo View(), musi Pan wybrac;
        Przejscie();

        cout << "\n";
        cout << "\n----------- x: " << Szerokosc << " ,y: " << Wysokosc << " ------------\n";
        View();
        cout << "\nLOOPEK\n";
    }

    return;
}

//void Engine::View()
//{
//    for (long i = 0; i < Wysokosc; i++) {
//        for (long j = 0; j < Szerokosc; j++) {
//            if (Plansza[i][j].CzyZyje()) {
//                std::cout << 'O';
//            }
//            else {
//                std::cout << '.';
//            }
//        }
//        std::cout << std::endl;
//    }
//}


