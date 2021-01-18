#include "stdafx.h"
#include "FLTK_View.h"

FLTK_View::FLTK_View(const int argc, char** const argv_)
	:Fl_Window(600, 800, "Zgadywarka")
{
	init();
}

void FLTK_View::init()
{
	resizable(output_log);

	pack_input.spacing(25);
	input_to_guess.value("15");
	input_to_guess.align(FL_ALIGN_TOP);

	input_limit.value("0");
	input_limit.align(FL_ALIGN_TOP);

	output_log.buffer(output_buffer);
	output_log.scrollbar_align(FL_ALIGN_RIGHT);

	button_start.callback([](Fl_Widget* sender, void* window) {
		reinterpret_cast<FLTK_View*>(window)->loadData();
		}, this);

	button_next_guessed.callback([](Fl_Widget* sender, void* window) {
		auto& buffer = reinterpret_cast<FLTK_View*>(window)->output_buffer;
		auto& display = reinterpret_cast<FLTK_View*>(window)->output_log;
		int i = buffer.highlight_selection()->end();
		if (i >= buffer.length() - 5)
			i = 0;

		if (buffer.findchar_forward(i, '!', &i))
			buffer.highlight(i, i + 1);
		else
			buffer.highlight(0, 0);

		display.scroll(buffer.count_lines(0, i), 0);
		}, this);
}

void FLTK_View::loadData()
{
	unsigned long long
		to_guess,
		limit;
	try {
		to_guess = std::stoull(input_to_guess.value());
		limit = std::stoull(input_limit.value());

		if(Z.play(to_guess, limit))
			output_buffer.text(Z.getLog().str().c_str());
		else
			output_buffer.text("Inncorect numbers!");
	}
	catch (...) {
		output_buffer.text("Inncorect numbers!");
	}
}
