#pragma once
#include "User.h"

class Binary_Search_User : public User
{
public:
	Binary_Search_User(const std::string name, User_Communication * const comms);
	virtual void guess() override;
};

