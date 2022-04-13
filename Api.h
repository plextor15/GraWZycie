#ifndef API_H
#define API_H

#include <windows.h>
#include "Engine.h"

//do wyswietlania w okienku
class Api : public Engine
{
private:
	HDC m_hdc;
	//short Wysokosc = 20;
	//short Szerokosc = 20;

public:
	Api(){}
	Api(const Api& t);
	virtual ~Api(){};
	const Api& operator=(const Engine& e);

	void View();	//virtual
	void GameLoop();

	void InitAPI(HWND hwnd);
};

#endif //!API_H
