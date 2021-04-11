#include <iostream>                  //???
using namespace std;                 //???

#include "Array.h"

Array::Array(){
	//Edycja = false;
	Szerokosc = 2;
	Wysokosc = 2;

}

Array::Array(long wys, long szer){
	Szerokosc = szer;
	Wysokosc = wys;
	//Edycja = false;

}

Array::~Array(){
	if (Plansza){
		for (long i = 0; i < Wysokosc; i++){
			delete[] Plansza[i];
		}
		delete[] Plansza;
	}

	if (PlanszaTMP) {
		for (long i = 0; i < Wysokosc; i++) {
			delete[] PlanszaTMP[i];
		}
		delete[] PlanszaTMP;
	}
}

void Array::Analiza(){
	//inicjalizacja Plansza i PlanszaTMP
	//PlanszaTMP = nullptr;

//???  --->    spr.
cout<<"\nPlansza przed Analiza()\n";
	for (long i = 0; i < Wysokosc; i++){
		for (long j = 0; j < Szerokosc; j++){
			cout<< Plansza[i][j].GetCell()<<" ";
		}
		cout<<endl;
	}
//???  <---

/*
	PlanszaTMP = new Cell* [Wysokosc];              //??? gdzie jest destrukcja tej tablicy? nie widze.
                                                    //??? destruktor to za malo, obiekt Array zyje caly czas podczas gry.
	for (long i = 0; i < Wysokosc; i++){
//???		Plansza[i] = new Cell[Szerokosc];
		PlanszaTMP[i] = new Cell[Szerokosc];         //???
	}
*/

	for (long i = 0; i < Wysokosc; i++){
		for (long j = 0; j < Szerokosc; j++){
			PlanszaTMP[i][j] = Plansza[i][j];        //??? wiersz 36 - 40 chyba zbedny?
		}
	}

	//DEBUG ONLY!!
	//int waskol = 0;
	//long doWysokosc = Wysokosc - 1;
	//long doSzerokosc = Szerokosc - 1;
	//cout << "\n-----------MOJE przed analiza krokow--------------\n";
	//for (long i = 1; i < doWysokosc; i++) {
	//	for (long j = 1; j < doSzerokosc; j++) {
	//		cout << "\n-----------" << waskol << "--------------\n";
	//		waskol++;
	//		AnalizaKroku(j, i);                   ///??? Blad jest w   AnalizaKroku(j, i);   z tego program nie wychodzi
	//	}
	//}
	//cout << "\n-----------MOJE po analiza krokow--------------\n";

	for (long i = 0; i < Wysokosc; i++) {
		for (long j = 0; j < Szerokosc; j++) {
			AnalizaKroku(j, i);                   ///??? Blad jest w   AnalizaKroku(j, i);   z tego program nie wychodzi
		}
	}

//???  --->    spr.
cout<<"\nPlansza po Analiza()\n";
cout << "x: " << Szerokosc << " , y: " << Wysokosc << "\n";
	for (long i = 0; i < Wysokosc; i++){
		for (long j = 0; j < Szerokosc; j++){
			cout << Plansza[i][j].GetCell() <<" ";
		}
		//system("PAUSE");
		cout<<endl;
	}
//???  <---

//??? zbedne;	
	return;
}

bool Array::SprawdzenieSasiadow(long pozX, long pozY){
	int iluSasiadowZyje = 0;
	long x = pozX;
	long y = pozY;

	if (y > 0) {
		if (x > 0) {
			if (Plansza[y - 1][x - 1].zywy) iluSasiadowZyje++;
		}
	
		if (Plansza[y - 1][x].zywy) iluSasiadowZyje++;
		
		if (x < Szerokosc-1) {
			if (Plansza[y - 1][x + 1].zywy) iluSasiadowZyje++;
		}
	}

	if (x > 0) {
		if (Plansza[y][x - 1].zywy) iluSasiadowZyje++;
	}
	if (x < Szerokosc-1) {
		if (Plansza[y][x + 1].zywy) iluSasiadowZyje++;
	}

	if (y < Wysokosc-1) {
		if (x > 0) {
			if (Plansza[y + 1][x - 1].zywy) iluSasiadowZyje++;
		}

		if (Plansza[y + 1][x].zywy) iluSasiadowZyje++;//DEBUG
		
		if (x < Szerokosc-1) {
			if (Plansza[y + 1][x + 1].zywy) iluSasiadowZyje++;
		}
	}

	//true - przezyje, false - umrze
	if (Plansza[y][x].zywy){
		if (iluSasiadowZyje==2 || iluSasiadowZyje == 3){
			return true;
		}
		else {
			return false;
		}
	}
	else{
		if (iluSasiadowZyje==3){
			return true;
		}
		else{
			return false;
		}
	}
}

void Array::AnalizaKroku(long pozX, long pozY){
	cout << "\nPrzedAnalizaKroku\n";
	bool CzyPrzezyje = SprawdzenieSasiadow(pozX, pozY);
	
	cout << "AnalizaKroku\n";
	if (CzyPrzezyje){
		PlanszaTMP[pozY][pozX].Ozyw();
	}
	else {	//teoretycznie niepotrzebne, ale jest zaby wszystko bylo jasne
		PlanszaTMP[pozY][pozX].Zabij();
	}
	cout << "ZanalizowanyKrok\n";
	return;
}

/*void Array::Przejscie(){
	for (long i = 0; i < Wysokosc; i++) {
		for (long j = 0; j < Szerokosc; j++) {
			Plansza[i][j] = PlanszaTMP[i][j];
		}
	}

	//if (PlanszaTMP) {
	//	for (long i = 0; i < Wysokosc; i++) {
	//		delete[] PlanszaTMP[i];
	//	}
	//	delete[] PlanszaTMP;
	//}

	return;
}*/