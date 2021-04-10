#include "Cell.h"

Cell::Cell() {
	zywy = false;
}

Cell::~Cell(){ //mozliwe ze niepotrzebne
}

bool Cell::CzyZyje(){
	return zywy;
}

void Cell::Zabij(){
	zywy = false;
	return;
}

void Cell::Ozyw(){
	zywy = true;
	return;
}
