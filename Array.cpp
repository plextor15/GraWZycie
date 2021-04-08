#include "Array.h"


Array::Array(){
	Edycja = false;
}

Array::Array(long wys, long szer)
{
	Szerokosc = szer;
	Wysokosc = wys;

	Plansza = new Cell* [Wysokosc];
	for (long i = 0; i < Wysokosc; i++)
	{
		Plansza[i] = new Cell[Szerokosc];
	}
}

Array::~Array()
{
	if (Plansza)
	{
		for (long i = 0; i < Wysokosc; i++)
		{
			delete[] Plansza[i];
		}
		delete[] Plansza;
	}	
}
