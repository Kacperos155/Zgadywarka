#include "User.h"

User::User(const std::string name, User_Communication* const comms)
	:name(name), comms(comms), ID(comms->register_user()) {}

const unsigned short User::getID() const
{
	return ID;
}

const std::string User::getName() const
{
	return name;
}

const std::vector<unsigned long long>& User::getLog() const
{
	return log;
}

void User::setUpperLimit(unsigned long long limit)
{
	upper_range = limit;
}

void User::react()
{
	auto answer = comms->receive_answer(ID);
	if (answer == User_Communication::Answer::Smaller)
		lower_range = guess_result;
	else if (answer == User_Communication::Answer::Bigger)
		upper_range = guess_result;
}

void User::guess()
{
	log.push_back(guess_result);
	comms->send_question(ID, guess_result);
}
