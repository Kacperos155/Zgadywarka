#pragma once
#include "stdafx.h"
#include "Zgadywarka.h"

class FLTK_View : public Fl_Window
{
	Zgadywarka_Controller Z;
	Fl_Pack
		pack_input{ 25, 25, 150, 0 };
	Fl_Int_Input
		input_to_guess{ 0, 0, 0, 20, "To guess" },
		input_limit{ 0, 0, 0, 20, "Limit" };
	Fl_Button
		button_start{ 0, 0, 0, 20, "Start guessing" },
		button_next_guessed{ 0, 0, 0, 20, "Next guessed" };
	Fl_End end_pack_input;

	Fl_Text_Buffer
		output_buffer;
	Fl_Text_Display
		output_log{ 200, 25, 375, 750 };

	void init();
	void loadData();

public:
	FLTK_View(const int argc, char** const argv_);
};

