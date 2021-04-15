#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <fstream>

#include "Array.h"

class Engine : protected Array
{
public:
	Engine();
	Engine(const Engine& e);
	virtual ~Engine();
	const Engine& operator=(const Engine& e);

	void Initialize();
	void Przejscie();
	virtual void View() = 0;
	void GameLoop();
};

#endif // !ENGINE_H
