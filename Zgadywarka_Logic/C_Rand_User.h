#pragma once
#include "User.h"
#include <cstdlib>
#include <ctime>

class C_Rand_User : public User
{
public:
	C_Rand_User(const std::string name, User_Communication * const comms);
	virtual void guess() override;
};

