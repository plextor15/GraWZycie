#ifndef TXT_H
#define TXT_H

#include <iostream>
#include "Engine.h"

//do wyswietlania w konsoli
class TxT : public Engine
{
private:
	//bool BlokadaKlawiatury = false;
	short Wysokosc = 20;                      //???
	short Szerokosc = 20;                     //???

public:
	char Martwy = ' ';                        //???
	char Zywy = '#';                          //???

	TxT(){}
	TxT(const TxT& t);
	virtual ~TxT(){};
	const TxT& operator=(const Engine& e);

	void View();	//virtual     //??? jesli daje Pan komentarz, to dlaczego nie pisze Pan jawnie virtual?
	void GameLoop();

	//void Blokada(bool zablokowane);		//ustawia blokade wczytywania znakow
	//void Rozdzielczosc(short wys, short szer);
	//void RozdzielczoscWys(short wys);
	//void RozdzielczoscSzer(short szer);

	//void WczytujZnaki();	//dziala jak cin >> x [Enter]
};

#endif // !TXT_H
