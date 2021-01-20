#include "Binary_Search_User.h"

Binary_Search_User::Binary_Search_User(const std::string name, User_Communication * const comms)
	:User(name, comms) {}

void Binary_Search_User::guess()
{
	binary_search();
	User::guess();
}
