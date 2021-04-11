#ifndef ARRAY_H
#define ARRAY_H

#include "Cell.h"



class Array
{
private:                                             //??? czy na pewno ma byc private, a nie protected?
                                                     //??? wtedy zbedne Set.. Get..
	//bool Edycja;		//blokada zeby nie zaczelo zyc podczas edycji
	long Szerokosc;
	long Wysokosc;

//	Cell** Plansza;	//wskaznik do tablicy 2d Celli
//	Cell** PlanszTMP;	//wskaxnik do tablicy przejsciowej

protected:
    Cell** Plansza;	//wskaznik do tablicy 2d Celli
	Cell** PlanszaTMP;	//wskaznik do tablicy przejsciowej

	Array();
	Array(long wys, long szer);
	~Array();

	bool SprawdzenieSasiadow(long pozX, long pozY);
	void AnalizaKroku(long pozX, long pozY);
	void Przejscie();

public:
	void Analiza();

	//bool GetTryb();
	//void TrybEdycji();
	//void TrybGry();

	void SetWysokosc(long wys);
	void SetSzerokosc(long szer);
	long GetWysokosc();
	long GetSzerokosc();

	friend class Engine;
};

#endif // !ARRAY_H
