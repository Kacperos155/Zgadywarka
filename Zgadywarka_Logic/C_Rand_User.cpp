#include "C_Rand_User.h"

C_Rand_User::C_Rand_User(const std::string name, User_Communication * const comms)
	:User(name, comms)
{
	srand(static_cast<unsigned>(time(NULL)));
}

void C_Rand_User::guess()
{
	auto range = upper_range - lower_range;
	guess_result = rand() % range;
	if (guess_result == 0)
		++guess_result;
	guess_result += lower_range;
	User::guess();
}
