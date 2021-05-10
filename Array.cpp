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
}

void Array::Analiza(){
	//inicjalizacja Plansza i PlanszaTMP
	//PlanszaTMP = nullptr;

	PlanszaTMP = new Cell* [Wysokosc];
	for (long i = 0; i < Wysokosc; i++){
		Plansza[i] = new Cell[Szerokosc];
	}

	for (long i = 0; i < Wysokosc; i++){
		for (long j = 0; j < Szerokosc; j++){
			PlanszaTMP[i][j] = Plansza[i][j];
		}
	}

	for (long i = 0; i < Wysokosc; i++) {
		for (long j = 0; j < Szerokosc; j++) {
			AnalizaKroku(j, i);
		}
	}

	return;
}

bool Array::SprawdzenieSasiadow(long pozX, long pozY){
	int iluSasiadowZyje = 0;
	long x = pozX;
	long y = pozY;

	if (Plansza[y - 1][x - 1].zywy) iluSasiadowZyje++;
	if (Plansza[y - 1][x].zywy) iluSasiadowZyje++;
	if (Plansza[y - 1][x + 1].zywy) iluSasiadowZyje++;
	
	if (Plansza[y][x - 1].zywy) iluSasiadowZyje++;
	if (Plansza[y][x + 1].zywy) iluSasiadowZyje++;
	
	if (Plansza[y + 1][x - 1].zywy) iluSasiadowZyje++;
	if (Plansza[y + 1][x].zywy) iluSasiadowZyje++;
	if (Plansza[y + 1][x + 1].zywy) iluSasiadowZyje++;

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
	}
}

void Array::AnalizaKroku(long pozX, long pozY){
	bool CzyPrzezyje = SprawdzenieSasiadow(pozX, pozY);
	
	if (CzyPrzezyje){
		PlanszaTMP[pozY][pozX].Ozyw();
	}
	else {	//teoretycznie niepotrzebne, ale jest zaby wszystko bylo jasne
		PlanszaTMP[pozY][pozX].Zabij();
	}
	return;
}

void Array::Przejscie(){
	for (long i = 0; i < Wysokosc; i++) {
		for (long j = 0; j < Szerokosc; j++) {
			Plansza[i][j] = PlanszaTMP[i][j];
		}
	}

	if (PlanszaTMP) {
		for (long i = 0; i < Wysokosc; i++) {
			delete[] PlanszaTMP[i];
		}
		delete[] PlanszaTMP;
	}

	return;
}

void Array::SetWysokosc(long wys){
	Wysokosc = wys;
	return;
}

void Array::SetSzerokosc(long szer){
	Szerokosc = szer;
	return;
}

long Array::GetWysokosc(){
	return Wysokosc;
}

long Array::GetSzerokosc(){
	return Szerokosc;
}