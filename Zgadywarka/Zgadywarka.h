#pragma once
#include "stdafx.h"
#include "../Zgadywarka_Logic/Zgadywarka_Logic.h"
#include <iostream>
#include <sstream>

class Zgadywarka_Controller
{
	Zgadywarka_Logic ZL;
	unsigned long long
		number_to_guess,
		limit;
	std::stringstream log;
	void print();

public:
	Zgadywarka_Controller();
	[[deprecated]] Zgadywarka_Controller(const int argc, char** const argv_);
	bool play(unsigned long long number_to_guess, unsigned long long limit);
	bool play();
	const std::stringstream& getLog() const;
};

