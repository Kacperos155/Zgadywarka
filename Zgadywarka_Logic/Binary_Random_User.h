#pragma once
#include "Random_User.h"

class Binary_Random_User : public Random_User
{
	User_Communication::Answer last_answer;
	unsigned short last_answer_counter;
public:
	Binary_Random_User(const std::string name, User_Communication* const comms);
	virtual void guess() override;
};

