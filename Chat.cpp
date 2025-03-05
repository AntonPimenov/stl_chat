#include "Chat.h"


void Chat::registerUser()
{
	string login, password, name;
	cout << "ВВедите логин: ";
	cin >> login;

	//проверка на уникальность логина
	if (users.find(login) != users.end())
	{
		cout << "Пользователь с таким логином уже существует!\n";
		return;
	}

	cout << "Введите пароль: ";
	cin >> password;
	cout << "Введите имя: ";
	cin >> name;

	users[login] = User(login, password, name);
	std::cout << "Пользователь зарегистрирован!\n";
}
// Вход в чат
bool Chat::login()
{
	std::string login, password;
	std::cout << "Введите логин: ";
	std::cin >> login;
	std::cout << "Введите пароль: ";
	std::cin >> password;

	// Поиск пользователя по логину
	auto it = users.find(login);
	if (it != users.end() && it->second.password == password) {
		currentUser = &it->second; // Устанавливаем текущего пользователя
		std::cout << "Вход выполнен! Добро пожаловать, " << currentUser->name << "!\n";
		return true;
	}

	std::cout << "Неверный логин или пароль!\n";
	return false;
	
}

//Отправка сообщения конкретному пользователю
void Chat::sendMessage()
{
	if (!currentUser)
	{
		cout << "Сначала войдите в систему!\n";
		return;
	}
	string to, text;
	cout << "Введите логин получателя: ";
	cin >> to;

	//проверка существования пользователя
	if (users.find(to) == users.end())
	{
		cout << "Такого пользователя нет!\n";
		return;
	}

	cout << "Введите текст сообщения: ";
	cin.ignore(); // игнорируем предыдущий ввод
	getline(cin, text);

	messages[to].emplace_back(currentUser->login, text); //добавляем сообщение получателю
	cout << "Сообщение отправленно!\n";
}
// Отправка сообщения всем пользователям
void Chat::broadcastMessage()
{
	if (!currentUser)
	{
		cout << "Сначала войдите в систему\n";
		return;
	}

	string text;
	cout << "Введите текст сообщения для всех: ";
	cin.ignore();
	getline(cin, text);

	for (const auto& user : users)
	{
		if (user.first != currentUser->login) // исключаем текущего пользователя
		{
			messages[user.first].emplace_back(currentUser->login, text);
		}
	}
	cout << "Сообщение отправлено всем пользователям!\n";
}
//Просмотр сообщений
void Chat::viewMessages()
{
	if (!currentUser)
	{
		cout << "Сначала войдите в систему\n";
		return;
	}

	cout << "Ваши сообщения:\n";
	auto it = messages.find(currentUser->login);
	if (it != messages.end())
	{
		for (const auto& msg : it->second)
		{
			cout << "От: " << msg.from << " | Сообщение: " << msg.text << endl;
		}
	}
	else
	{
		cout << "У вас нет сообщений!\n";
	}
}
// Просмотр всех пользователей
void Chat::viewAllUsers()
{
	if (!currentUser) {
		std::cout << "Сначала войдите в систему!\n";
		return;
	}

	std::cout << "Список всех пользователей:\n";
	for (const auto& user : users) {
		if (user.first != currentUser->login) { // Исключаем текущего пользователя из списка
			std::cout << "Логин: " << user.first << " | Имя: " << user.second.name << "\n";
		}
	}
}
// Выход из чата
void Chat::logout()
{
	currentUser = nullptr;
	std::cout << "Вы вышли из системы.\n";
}

