#pragma once
#include "User.h"

class Exponential_Search_User : public User
{
	bool exponential_mode;
public:
	Exponential_Search_User(const std::string name, User_Communication* const comms);
	virtual void guess() override;
};

