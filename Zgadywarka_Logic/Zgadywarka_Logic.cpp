#include "Zgadywarka_Logic.h"

Zgadywarka_Logic::Zgadywarka_Logic()
	:number_to_guess(0) {}

void Zgadywarka_Logic::play(unsigned long long limit, unsigned long long number_to_guess)
{
	this->number_to_guess = number_to_guess;
	unsigned long long turn = 0;
	std::vector<User*> to_remove;

	for (auto&& u : Users) {
		u->setUpperLimit(limit);
		Users_in_game.push_back(u.get());
	}

	//Turns
	while (Users_in_game.size()) {
		for (auto&& u : Users_in_game) {
			u->guess();
			auto respond = comms.receive_question(u->getID());

			if (respond == number_to_guess) {
				comms.send_answer(u->getID(), User_Communication::Answer::Guessed);
				to_remove.push_back(u);
			}
			else if (respond < number_to_guess)
				comms.send_answer(u->getID(), User_Communication::Answer::Smaller);
			else if (respond > number_to_guess)
				comms.send_answer(u->getID(), User_Communication::Answer::Bigger);
			u->react();
		}
		++turn;
		//Removing "winners"
		for (auto&& u : to_remove) {
			for (auto it = Users_in_game.begin(); it != Users_in_game.end(); ++it) {
				if (*it == u) {
					Users_in_game.erase(it);
					break;
				}
			}
		}
		to_remove.clear();
	}
}

Zgadywarka_Logic& Zgadywarka_Logic::addUser(User_Type ut, std::string name)
{
	if(ut == User_Type::Binary_Search)
		Users.emplace_back(std::make_unique<Binary_Search_User>(name, &comms));
	else if(ut == User_Type::C_Rand)
		Users.emplace_back(std::make_unique<C_Rand_User>(name, &comms));
	else if(ut == User_Type::Random_MT19937)
		Users.emplace_back(std::make_unique<Random_User>(name, &comms));
	return *this;
}

void Zgadywarka_Logic::clearUsers()
{
	Users.clear();
}

const std::vector<std::unique_ptr<User>>& Zgadywarka_Logic::getUsers() const
{
	return Users;
}

const unsigned long long Zgadywarka_Logic::getLastGuessedNumber() const
{
	return number_to_guess;
}
