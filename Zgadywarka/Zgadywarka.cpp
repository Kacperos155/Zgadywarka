#include "stdafx.h"
#include "Zgadywarka.h"

Zgadywarka_Controller::Zgadywarka_Controller()
	:ZL(), number_to_guess(0), limit(0) {}

Zgadywarka_Controller::Zgadywarka_Controller(const int argc, char** const argv_)
	: ZL(), number_to_guess(0), limit(0)
{
	const std::vector<std::string> argv(argv_, argv_ + argc);
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

void Zgadywarka_Controller::print()
{
	summary = std::stringstream();
	log = std::stringstream();
	unsigned long long max_turns = 0;
	unsigned short max_chars = 0;
	auto printUser = [&](std::stringstream& ss, const std::unique_ptr<User>& u) {
		ss.width(max_chars);
		ss << std::left << u->getName();
		ss.width(0);
		ss << "\t";
	};

	//Geting max values
	for (auto&& u : ZL.getUsers()) {
		if (u->getLog().size() > max_turns)
			max_turns = u->getLog().size();
		if (max_chars < u->getName().size())
			max_chars = static_cast<unsigned short>(u->getName().size());
	}
	max_chars += 5;

	//Short log
	summary << "Number to guess: " << ZL.getLastGuessedNumber() << "\n";
	summary << "From 1 to " << ZL.getLastLimit() - 1 << "\n\n";

	for (auto&& u : ZL.getUsers()) {
		printUser(summary, u);
		summary << " finished in " << u->getLog().size() << " turns.\n";
	}

	//Detailed log
	for (unsigned long long i = 0; i < max_turns; ++i) {
		log << "* Turn: " << i + 1 << " *\n";

		for (auto&& u : ZL.getUsers()) {
			if (u->getLog().size() >= (i + 1)) {
				printUser(log, u);

				if (u->getLog().size() == (i + 1)) {
					if (ZL.getLastGuessedNumber() == u->getLog()[i])
						log << " guessed number " << u->getLog()[i] << " !\n";
					else
						log << " time out !\n";
				}
				else if (u->getLog().size() > i)
					log << " is guessing " << u->getLog()[i] << "\n";
			}
		}
		log << "\n";
	}
}

bool Zgadywarka_Controller::play(unsigned long long number_to_guess, unsigned long long limit)
{
	this->number_to_guess = number_to_guess;
	this->limit = limit;
	return play();
}

bool Zgadywarka_Controller::play()
{
	ZL.clearUsers();

	ZL.addUser(User_Type::Binary_Search, "Binary");
	ZL.addUser(User_Type::Binary_Random, "Binarandom");
	ZL.addUser(User_Type::Random_MT19937, "Random C++");
	ZL.addUser(User_Type::C_Rand, "Random C");
	ZL.addUser(User_Type::Exponential_Search, "Exponential");

	if (ZL.play(number_to_guess, limit)) {
		print();
		return true;
	}
	return false;
}

const std::stringstream& Zgadywarka_Controller::getSummary() const
{
	return summary;
}

const std::stringstream& Zgadywarka_Controller::getLog() const
{
	return log;
}
