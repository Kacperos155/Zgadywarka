#pragma once
#include "User.h"
#include <random>

class Random_User : public User
{
	std::mt19937_64 randomise_engine;

public:
	Random_User(const std::string name, User_Communication * const comms);
	virtual void guess();
};

