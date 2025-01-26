#include <iostream>
#include <stack>
#include <string>
#include "bracket_error.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	stack<char> stack;

	string line;

	try
	{
		cout << "\nвведите строку\n";

		getline(cin, line, ';');
		//стек не поддерживает for с диапозоном
		for (size_t i = 0; i < line.size(); i++)
		{
			//проверяем является ли символ открывающей скобкой
			if (line[i] == '(' || line[i] == '[' || line[i] == '{')
			{
				//если тaк то записываем в стек
				stack.push(line[i]);
			}


			//в ином случве проверяем, является ли символ закрывающей скобкой
			else if (line[i] == ')' || line[i] == ']' || line[i] == '}' && !stack.empty() && stack.top() == line[i])
			{
				if (stack.empty() || stack.top() != '(' || stack.top() != '[' || stack.top() != '{') throw bracket_error("скобки расставлены не верно");
				//если у скобки нашли пару, удаляем последнюю открывающую скобку из стека
				stack.pop();
			}


		}
		cout << "\nскобки расставлены верно\n";

	}

	catch (const bracket_error& bracket)
	{
		cout << bracket.what();
	}
	return 0;
}