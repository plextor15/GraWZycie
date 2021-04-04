#include "TxT.h"

int main() {
	Engine* GraWZycie = new TxT();
	GraWZycie->Initialize();
	GraWZycie->Start();
	GraWZycie->GameLoop();

	return 0;
}
