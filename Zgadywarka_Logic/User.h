#pragma once
#include "User_Communication.h"
#include <vector>
#include <string>

class User
{
protected:
	const std::string name;
	unsigned long long
		lower_range = 0,
		upper_range = 0 - 1,
		guess_result = 0;

	User_Communication* const comms;
	const unsigned short ID;
	std::vector<unsigned long long> log;

public:
	User(const std::string name, User_Communication* const comms);
	const unsigned short getID() const;
	const std::string getName() const;
	const std::vector<unsigned long long>& getLog() const;

	void setUpperLimit(unsigned long long limit);
	void react();
	virtual void guess();
};

