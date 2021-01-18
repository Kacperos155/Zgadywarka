#include "stdafx.h"
#include "FLTK_View.h"
#include "FLTK_View.h"
#include <string>

int main(int argc, char** argv) {
	FLTK_View FLTK(argc, argv);
	FLTK.show();
	return Fl::run();
}