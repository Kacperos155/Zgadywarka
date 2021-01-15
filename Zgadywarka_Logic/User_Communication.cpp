#include "User_Communication.h"

unsigned short User_Communication::register_user()
{
    Channels.emplace_back(Message());
    return static_cast<unsigned short>(Channels.size() - 1);
}

void User_Communication::send_question(const unsigned short channel, const unsigned long long question)
{
    Channels[channel].question = question;
}

const unsigned long long User_Communication::receive_question(const unsigned short channel) const
{
    return Channels[channel].question;
}

void User_Communication::send_answer(const unsigned short channel, const Answer answer)
{
    Channels[channel].answer = answer;
}

const User_Communication::Answer User_Communication::receive_answer(const unsigned short channel) const
{
    return Channels[channel].answer;
}
