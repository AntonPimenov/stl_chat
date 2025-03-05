#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "User.h"
#include "Message.h"

using namespace std;

class Chat
{
private:
	map<string, User> users; //хранение пользователей (ключ: логин)
	map<string, vector<Message>> messages; //хранение сообщений (ключ: логин получателя)
	User* currentUser = nullptr; //указатель на текущего пользователя

public:
	
	void registerUser(); // регистрация нового пользователя
	bool login(); // вход в чат
	void sendMessage(); // отправка сообщения конкретному пользователю
	void broadcastMessage(); // отпраавка сообщения всем пользователям
	void viewMessages(); // просотр сообщений
	void viewAllUsers(); // просмотр всех пользователей
	void logout(); // выод из чата 
};

