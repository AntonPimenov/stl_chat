#include <iostream>
#include "Chat.h"
#include "User.h"
#include "Message.h"
#include "locale"

int main()
{
	setlocale(LC_ALL, "RU");
	Chat chat;
    int choice;

    while (true) {
        std::cout << "\n1. Регистрация\n2. Вход\n3. Отправить сообщение\n4. Отправить сообщение всем\n5. Просмотреть сообщения\n6. Просмотреть всех пользователей\n7. Выход\nВыберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            chat.registerUser();
            break;
        case 2:
            chat.login();
            break;
        case 3:
            chat.sendMessage();
            break;
        case 4:
            chat.broadcastMessage();
            break;
        case 5:
            chat.viewMessages();
            break;
        case 6:
            chat.viewAllUsers();
            break;
        case 7:
            chat.logout();
            return 0;
        default:
            std::cout << "Неверный выбор!\n";
        }
    }
	
	system("pause");
}