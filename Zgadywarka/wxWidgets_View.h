#pragma once
#include "stdafx.h"
#include "Zgadywarka.h"

class wxWidgets_View : public wxApp
{
	class MainFrame : public wxFrame {
		Zgadywarka_Controller Z;

		wxIntegerValidator<unsigned long> int_validator;
		wxBoxSizer
			* main_horizontal_sizer = new wxBoxSizer(wxHORIZONTAL),
			* controls_sizer = new wxBoxSizer(wxVERTICAL),
			* results_sizer = new wxBoxSizer(wxVERTICAL);
		wxStaticText
			* input_to_guess_label = new wxStaticText(this, -1, "To guess"),
			* input_limit_label = new wxStaticText(this, -1, "Limit");
		wxTextCtrl
			* summary_output = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE | wxTE_NOHIDESEL),
			* log_output = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE | wxTE_NOHIDESEL),
			* input_to_guess = new wxTextCtrl(this, -1, "15"),
			* input_limit = new wxTextCtrl(this, -1);
		wxButton
			* guess_button = new wxButton(this, -1, "Guess");

		void guess_and_print(wxCommandEvent&);
	public:
		MainFrame();
	};
	MainFrame* frame = new MainFrame();
public:
	bool OnInit() override;
};

