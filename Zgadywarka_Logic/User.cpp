#include "User.h"

User::User(const std::string name, User_Communication* const comms)
	:name(name), comms(comms), ID(comms->register_user()) {}

void User::binary_search()
{
	auto last_result = guess_result;
	guess_result = 0;
	guess_result += lower_range / 2;
	guess_result += upper_range / 2;

	if (last_result == guess_result)
		++guess_result;
}

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
