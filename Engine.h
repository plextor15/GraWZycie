#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <fstream>

#include "Array.h"

//moze array to Engine
class Engine : protected Array
{
private:
	bool PAUZA = false;
	bool WYJSCIE = false;
	unsigned short fps = 10;

public:
	Engine();
	Engine(const Engine& e);
	~Engine();
	const Engine& operator=(const Engine& e);

	void Initialize();
	//void Start();
	void Przejscie();
	virtual void View() = 0;                          //??? albo Przejscie() albo View(), musi Pan wybrac;
	void GameLoop();
	
	
	//void Pause();
	//void Resume();
	//void Quit();

	//void Load(std::string DoZaladowania);
	//void Save(std::string DoZapisania);

	friend class TxT;                    //??? TxT dzisdziczy Engine, wiec friend jrst zbedne; wystarczy enkapsulacja 'protected' zamiast 'private';
	//friend class aPI;
};

#endif // !ENGINE_H
