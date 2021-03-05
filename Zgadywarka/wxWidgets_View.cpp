#include "stdafx.h"
#include <limits>
#include "wxWidgets_View.h"

bool wxWidgets_View::OnInit()
{
	frame->Show(true);
	return true;
}

void wxWidgets_View::MainFrame::guess_and_print(wxCommandEvent&)
{
	unsigned long long
		to_guess = 0,
		limit = 0;

	try {
		to_guess = std::stoull(input_to_guess->GetValue().ToStdString());
		if (input_limit->GetValue().size())
			limit = std::stoull(input_limit->GetValue().ToStdString());

		if (Z.play(to_guess, limit)) {
			summary_output->SetValue(Z.getSummary().str());
			log_output->SetValue(Z.getLog().str());
		}
		else
			log_output->SetLabelText("Inncorect numbers!");
	}
	catch (...) {
		log_output->SetLabelText("Inncorect numbers!");
	}
}

wxWidgets_View::MainFrame::MainFrame()
	: wxFrame(nullptr, wxID_ANY, "Zgadywarka")
{
	int_validator.SuppressBellOnError(true);
	summary_output->SetMinSize(wxSize(300,150));
	log_output->SetMinSize(wxSize(300,400));
	summary_output->SetMargins(5);
	log_output->SetMargins(5);
	input_to_guess->SetWindowStyle(wxALIGN_CENTER);
	input_limit->SetWindowStyle(wxALIGN_CENTER);
	input_to_guess->SetValidator(int_validator);
	input_limit->SetValidator(int_validator);

	main_horizontal_sizer->Add(controls_sizer, wxSizerFlags().Expand());
	main_horizontal_sizer->Add(results_sizer, wxSizerFlags(1).Expand());
	results_sizer->Add(summary_output, wxSizerFlags().Expand().Border(wxALL, 10));
	results_sizer->Add(log_output, wxSizerFlags(10).Expand().Border(wxALL, 10));

	auto& label_placement = wxSizerFlags().Centre().Border(wxALL xor wxBOTTOM);
	auto& text_placement = wxSizerFlags().Centre().Border(wxALL xor wxTOP).Expand();
	auto& button_placement = wxSizerFlags().Expand().Border();

	controls_sizer->Add(input_to_guess_label, label_placement);
	controls_sizer->Add(input_to_guess, text_placement);
	controls_sizer->Add(input_limit_label, label_placement);
	controls_sizer->Add(input_limit, text_placement);
	controls_sizer->Add(guess_button, button_placement);

	SetSizerAndFit(main_horizontal_sizer);

	guess_button->Bind(wxEVT_BUTTON, &MainFrame::guess_and_print, this);
	
}