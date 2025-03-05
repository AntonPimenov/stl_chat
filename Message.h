#pragma once
#include <iostream>
#include <string>

class Message
{
public:
	std::string from;
	std::string text;

	Message(const std::string& f, const std::string& txt): from(f), text(txt)
	{
	}

};

