#include "Zgadywarka.h"

Zgadywarka_Controller::Zgadywarka_Controller()
	:ZL(), argv(), number_to_guess(0), limit(0) {}

Zgadywarka_Controller::Zgadywarka_Controller(const int argc, char** const argv_)
	: ZL(), argv(argv_, argv_ + argc), number_to_guess(0), limit(0)
{
	if (argv.size() >= 2) {
		try {
			number_to_guess = std::stoull(argv[1]);
			limit = 10;
			for (int i = 0; i < argv[1].size() - 1; ++i)
				limit *= 10;
		}
		catch (std::invalid_argument err) {
			std::cerr << "Invalid #1 argument \n";
		}
	}
	if (argv.size() >= 3) {
		try {
			limit = std::stoull(argv[2]);
		}
		catch (std::invalid_argument err) {
			std::cerr << "Invalid #2 argument \n";
		}
	}
}

Zgadywarka_Logic& Zgadywarka_Controller::getLogic()
{
	return ZL;
}

void Zgadywarka_Controller::print()
{
	std::cout << "Liczba do zgadniecia: " << ZL.getLastGuessedNumber() << "\n";
	unsigned long long max_turns = 0;
	for (auto&& u : ZL.getUsers()) {
		if (u->getLog().size() > max_turns)
			max_turns = u->getLog().size();
	}

	for (unsigned long long i = 0; i < max_turns; ++i) {
		std::cout << "-- Tura: " << i + 1 << "\n";
		for (auto&& u : ZL.getUsers()) {
			if (u->getLog().size() == (i + 1)) {
				std::cout << u->getName() << "\t odgadl liczbe " << u->getLog()[i] << " !\n";
			}
			else if (u->getLog().size() > i) {
				std::cout << u->getName() << "\t zgaduje " << u->getLog()[i] << "\n";
			}
		}
		std::cout << "\n";
	}
}

void Zgadywarka_Controller::play()
{
	ZL.clearUsers();
	if (number_to_guess == 0)
		return;

	ZL.addUser(User_Type::Binary_Search, "Binarek");
	ZL.addUser(User_Type::C_Rand, "Stary Lotek");
	ZL.addUser(User_Type::Random_MT19937, "Suprandom");
	ZL.play(limit, number_to_guess);
}
