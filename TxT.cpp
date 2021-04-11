#include "TxT.h"
#include <iostream>

//void TxT::GameLoop(){
//    while (true)
//    {
//        Analiza();
//        Przejscie();
//        View(); //nie ma juz Plansza TMP
//    }
//    return;
//}

TxT::TxT(){

}

void TxT::View(){
    std::cout << "\nView(): " << Szerokosc << " , " << Wysokosc << "\n";

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

//void TxT::GameLoop() {
//    while (true)
//    {
//        std::cout << "\n----------- x: " << Szerokosc << " ,y: " << Wysokosc << " ------------\n";
//        system("PAUSE");
//
//        Analiza();
//        //???        Przejscie();          //??? albo Przejscie() albo View(), musi Pan wybrac;
//        Przejscie();
//
//        std::cout << "\n";
//        View();
//    }
//
//    return;
//}