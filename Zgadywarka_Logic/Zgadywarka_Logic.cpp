#include "Zgadywarka_Logic.h"

Zgadywarka_Logic::Zgadywarka_Logic()
	:number_to_guess(0), limit(0) {}

unsigned long long Zgadywarka_Logic::calcLimit(unsigned long long number_to_guess)
{
	constexpr unsigned long long max_ull = std::numeric_limits<unsigned long long>::max();
	if (number_to_guess > max_ull / 10)
		return max_ull;

	unsigned long long l10 = 10;
	while (l10 < number_to_guess)
		l10 *= 10;
	return l10;
}

bool Zgadywarka_Logic::play(unsigned long long number_to_guess_, unsigned long long limit_)
{
	this->number_to_guess = number_to_guess_;
	unsigned long long turn = 0;
	std::vector<User*> to_remove;

	this->limit = limit_;
	if (limit == 0)
		limit = calcLimit(number_to_guess);

	if ((number_to_guess >= limit)
		|| (number_to_guess <= 0)
		|| (number_to_guess == std::numeric_limits<unsigned long long>::max()))
		return false;

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
		//Turns limit
		if (turn >= turns_limit) {
			Users_in_game.clear();
			break;
		}
	}
	return true;
}

Zgadywarka_Logic& Zgadywarka_Logic::addUser(User_Type ut, std::string name)
{
	if (ut == User_Type::Binary_Search)
		Users.emplace_back(std::make_unique<Binary_Search_User>(name, &comms));
	else if (ut == User_Type::C_Rand)
		Users.emplace_back(std::make_unique<C_Rand_User>(name, &comms));
	else if (ut == User_Type::Random_MT19937)
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

const unsigned long long Zgadywarka_Logic::getLastLimit() const
{
	return limit;
}

const unsigned long long Zgadywarka_Logic::getTurnsLimit() const
{
	return turns_limit;
}
