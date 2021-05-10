#ifndef TXT_H
#define TXT_H

#include <iostream>
#include <windows.h> //dla Sleep
#include "Engine.h"

//do wyswietlania w konsoli
class TxT : public Engine
{
public:
	short ileKlatka;
	char Martwy = ' ';
	char Zywy = '#';

	TxT();
	TxT(const TxT& t);
	virtual ~TxT() {};
	const TxT& operator=(const Engine& e);

	virtual void View();
};

#endif // !TXT_H
