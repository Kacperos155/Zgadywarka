#pragma once
#include "User_Communication.h"
#include "Binary_Search_User.h"
#include "C_Rand_User.h"
#include "Random_User.h"
#include <vector>
#include <memory>

enum class User_Type {
	Binary_Search,
	C_Rand,
	Random_MT19937
};

class Zgadywarka_Logic
{
	User_Communication comms;
	std::vector<std::unique_ptr<User>> Users;
	std::vector<User*> Users_in_game;
	unsigned long long number_to_guess;

public:
	Zgadywarka_Logic();
	void play(unsigned long long limit, unsigned long long number_to_guess = 0);
	Zgadywarka_Logic& addUser(User_Type ut, std::string name);
	void clearUsers();
	const std::vector<std::unique_ptr<User>>& getUsers() const;
	const unsigned long long getLastGuessedNumber() const;
};

