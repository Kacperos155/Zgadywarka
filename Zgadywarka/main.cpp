#include "Zgadywarka.h"
#include <string>

int main(int argc, char** argv) {
	auto System = Zgadywarka_Controller(argc, argv);
	System.play();
	System.print();
}