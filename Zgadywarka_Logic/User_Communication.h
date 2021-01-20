#pragma once
#include <vector>

class User_Communication
{
public:
	enum class Answer {
		Guessed,
		Smaller,
		Bigger
	};

	unsigned short register_user();
	void send_question(const unsigned short channel, const unsigned long long question);
	const unsigned long long receive_question(const unsigned short channel) const;
	void send_answer(const unsigned short channel, const Answer answer);
	const Answer receive_answer(const unsigned short channel) const;

private:
	struct Message {
		unsigned long long question;
		Answer answer;
	};

	std::vector<Message> Channels;
};

