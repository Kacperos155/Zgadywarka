#include "Binary_Random_User.h"

Binary_Random_User::Binary_Random_User(const std::string name, User_Communication* const comms)
	:Random_User(name, comms), last_answer(User_Communication::Answer::Guessed), last_answer_counter(0) {}

void Binary_Random_User::guess()
{
	auto answer = comms->receive_answer(ID);
	if (answer == last_answer)
		++last_answer_counter;
	else {
		last_answer_counter = 0;
		last_answer = answer;
	}

	if (last_answer_counter >= 2) {
		last_answer_counter = 0;
		Random_User::guess();
	}
	else {
		guess_result = (lower_range + upper_range + 1) / 2;
		User::guess();
	}
}
