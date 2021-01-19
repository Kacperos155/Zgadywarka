#pragma once
#include "User_Communication.h"
#include "Binary_Search_User.h"
#include "C_Rand_User.h"
#include "Random_User.h"
#include "Binary_Random_User.h"
#include <vector>
#include <memory>
#include <limits>

enum class User_Type {
	Binary_Search,
	C_Rand,
	Random_MT19937,
	Binary_Random
};

class Zgadywarka_Logic
{
	User_Communication comms;
	std::vector<std::unique_ptr<User>> Users;
	std::vector<User*> Users_in_game;
	unsigned long long
		number_to_guess,
		limit;
	const unsigned long long turns_limit = 1'000'000;
	unsigned long long calcLimit(unsigned long long number_to_guess);

public:
	Zgadywarka_Logic();
	bool play(unsigned long long number_to_guess = 0, unsigned long long limit = 0);
	Zgadywarka_Logic& addUser(User_Type ut, std::string name);
	void clearUsers();
	const std::vector<std::unique_ptr<User>>& getUsers() const;
	const unsigned long long getLastGuessedNumber() const;
	const unsigned long long getLastLimit() const;
	const unsigned long long getTurnsLimit() const;
};

