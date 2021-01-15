#include "Random_User.h"

Random_User::Random_User(const std::string name, User_Communication * const comms)
	:User(name, comms) {
	randomise_engine.seed(std::random_device()() | getID());
}

void Random_User::guess()
{
	std::uniform_int_distribution<unsigned long long> randomizing(lower_range + 1, upper_range - 1);
	guess_result = randomizing(randomise_engine);
	User::guess();
}
