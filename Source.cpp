#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	stack<char> stack;

	char symbol, braket;

	string line;

	cout << "\nвведите строку\n";

	getline(cin, line, ';');

	for (size_t i = 0; i < line.size(); i++)
	{
		symbol = line[i];
		//проверяем является ли символ открывающей скобкой
		if (symbol == '(' || symbol == '[' || symbol == '{')
		{
			//если тaк то записываем в стек
			stack.push(symbol);
		}
		//в ином случве проверяем, является ли символ закрывающей скобкой
		else if (symbol == ')' || symbol == ']' || symbol == '}')
		{
			//проверяем, есть ли у скобки пара
			if (symbol == ')')
			{
				braket = '(';
			}

			else if (symbol == ']')
			{
				braket = '[';
			}
			
			else 
			{
				braket = '{';
			}
			//проверяем остались ли скобки в стеке или последняя скобка не является открывающей
			if (stack.empty() || stack.top() != braket)
			{
				cout << "\nскобки расставлены неправильно\n";
				return 0;
			}

			//если у скобки нашли пару, удаляем последнюю открывающую скобку из стека
			stack.pop();
		}
	}
	cout << "\nскобки расставлены верно\n";

	return 0;
}