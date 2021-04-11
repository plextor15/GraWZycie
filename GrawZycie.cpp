#include <iostream>                  //???
using namespace std;                 //???

#include "TxT.h"

int main() {
	Engine* GraWZycie = new TxT();
	GraWZycie->Initialize();                     //??? Initialize() mozna wstawic do GameLoop();
cout<<"Init OK\n";                               //???
	//GraWZycie->Start();
	GraWZycie->GameLoop();
cout<<"Loop\n";                                  //???

	return 0;
}
