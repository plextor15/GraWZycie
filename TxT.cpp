#include "TxT.h"
//#include <iostream>

TxT::TxT(){
    ileKlatka = 1000;
}

void TxT::View(){
    for (long i = 0; i < Wysokosc; i++){
        for (long j = 0; j < Szerokosc; j++){
            if (Plansza[i][j].CzyZyje()){
                std::cout << Zywy;
            }
            else {
                std::cout << Martwy;
            }
        }
        std::cout << std::endl;
    }

    Sleep(ileKlatka);
	return;
}