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
	
	bool SprawdzenieSasiadow();
	void Zabij();
	void Ozyw();

	/*long GetX();
	long GetY();
	void SetX(long x);
	void SetY(long y);*/

	friend class Array;
};

#endif // !CELL_H
