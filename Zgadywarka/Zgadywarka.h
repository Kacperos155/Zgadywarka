#pragma once
#include "Zgadywarka_Logic.h"
#include <iostream>

class Zgadywarka_Controller
{
	Zgadywarka_Logic ZL;
	const std::vector<std::string> argv;
	unsigned long long
		number_to_guess,
		limit;

public:
	Zgadywarka_Controller();
	Zgadywarka_Controller(const int argc, char** const argv_);
	[[deprecated]] Zgadywarka_Logic& getLogic();
	void print();
	void play();
};

