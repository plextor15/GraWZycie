#ifndef ARRAY_H
#define ARRAY_H

#include "Cell.h"

class Array
{
protected:
	long Szerokosc;
	long Wysokosc;

    Cell** Plansza;	//wskaznik do tablicy 2d Celli
	Cell** PlanszaTMP;	//wskaznik do tablicy przejsciowej

	Array();
	Array(long wys, long szer);
	~Array();

	bool SprawdzenieSasiadow(long pozX, long pozY);
	void AnalizaKroku(long pozX, long pozY);

public:
	void Analiza();
};

#endif // !ARRAY_H
