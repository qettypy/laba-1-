// GopOdinchik laba parol.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <string>

// Функция для генерации случайного пароля
std::string generatePassword(int length) {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, charset.size() - 1);

    std::string password;
    for (int i = 0; i < length; i++) {
        password += charset[distribution(gen)];
    }

    return password;
}

int main() 
{
    setlocale(LC_ALL, "");
    
    int passwordLength;

    std::cout << "Введите длину пароля: ";
    std::cin >> passwordLength;

    if (passwordLength < 1) {
        std::cout << "Длина пароля должна быть положительным числом." << std::endl;
        return 1;
    }

    std::string password = generatePassword(passwordLength);
    std::cout << "Сгенерированный пароль: " << password << std::endl;

    // Пример проверки на длину пароля
    if (password.length() >= 8) {
        std::cout << "Пароль соответствует минимальной длине." << std::endl;
    }
    else {
        std::cout << "Пароль слишком короткий. Минимальная длина пароля - 8 символов." << std::endl;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
