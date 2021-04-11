#ifndef CELL_H
#define CELL_H

class Cell
{
private:
	//long X;
	//long Y;
	bool zywy;

public:
	Cell();
	~Cell();

	//bool SprawdzenieSasiadow();
	bool CzyZyje();
	void Zabij();
	void Ozyw();

bool GetCell() { return zywy; }    //??? dodalem dla testu;
void SetCell(bool bx) { zywy = bx; }    //??? dodalem dla testu. Proponuje zostawic i korzystac w  Engine::Initialize()
	//long GetX();
	//long GetY();
	//void SetX(long x);
	//void SetY(long y);

	friend class Array;
};

#endif // !CELL_H
