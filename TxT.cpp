#include "TxT.h"
#include <iostream>

void TxT::GameLoop(){
    char klkl; //DEBUG ONLY!!
    while (true)
    {
        Analiza();
        Przejscie();
        View(); //nie ma juz Plansza TMP

        std::cin >> klkl;   //DEBUG ONLY!!
    }
    return;
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

	return;
}

