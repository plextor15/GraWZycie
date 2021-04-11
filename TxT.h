#ifndef TXT_H
#define TXT_H

#include <iostream>
#include "Engine.h"

//do wyswietlania w konsoli
class TxT : public Engine
{
public:
	char Martwy = ' ';
	char Zywy = '#';

	TxT();
	TxT(const TxT& t);
	virtual ~TxT(){};
	const TxT& operator=(const Engine& e);

	virtual void View();
};

#endif // !TXT_H
