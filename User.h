#pragma once
#include <string>
#include <iostream>

class User
{
public:
	std::string login;
	std::string password;
	std::string name;
	User() {};
	User(const std::string& l, const std::string& p, const std::string& n)
		: login(l), password(p), name(n) {
	}

};
