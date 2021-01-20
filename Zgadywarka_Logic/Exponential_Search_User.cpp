#include "Exponential_Search_User.h"

Exponential_Search_User::Exponential_Search_User(const std::string name, User_Communication* const comms)
	:User(name, comms), exponential_mode(true)
{
	guess_result = 1;
}

void Exponential_Search_User::guess()
{
	if (guess_result == 9223372036854775808)
		exponential_mode = 1;
	if (exponential_mode) {
		if (comms->receive_answer(getID()) == User_Communication::Answer::Bigger) {
			exponential_mode = false;
			upper_range = guess_result;
		}
		else {
			auto exp2 = guess_result * 2;
			if ((exp2 < upper_range) && (exp2 != 0)) {
				guess_result = exp2;
				User::guess();
				return;
			}
			else {
				exponential_mode = false;
				lower_range = guess_result;
			}
		}
	}
	binary_search();
	User::guess();
}
