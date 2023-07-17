// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include <variant>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto varibl = get_variant();
	if (std::holds_alternative<int>(varibl)) {
		std::cout << std::get<int>(varibl) * 2 << std::endl;
	}
	if (std::holds_alternative<std::string>(varibl)) {
		std::cout << std::get<std::string>(varibl) << std::endl;
	}
	if (std::holds_alternative<std::vector<int>>(varibl))
	{
		for (const auto& n : (std::get<std::vector<int>>(varibl)))
		{
			std::cout << n << " ";
		}
		std::cout << std::endl;



	}
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
