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

	cout << "\n������� ������\n";

	getline(cin, line, ';');

	for (size_t i = 0; i < line.size(); i++)
	{
		symbol = line[i];
		//��������� �������� �� ������ ����������� �������
		if (symbol == '(' || symbol == '[' || symbol == '{')
		{
			//���� �a� �� ���������� � ����
			stack.push(symbol);
		}
		//� ���� ������ ���������, �������� �� ������ ����������� �������
		else if (symbol == ')' || symbol == ']' || symbol == '}')
		{
			//���������, ���� �� � ������ ����
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
			//��������� �������� �� ������ � ����� ��� ��������� ������ �� �������� �����������
			if (stack.empty() || stack.top() != braket)
			{
				cout << "\n������ ����������� �����������\n";
				return 0;
			}

			//���� � ������ ����� ����, ������� ��������� ����������� ������ �� �����
			stack.pop();
		}
	}
	cout << "\n������ ����������� �����\n";

	return 0;
}