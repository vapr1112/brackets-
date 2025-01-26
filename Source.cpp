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
		cout << "\n������� ������\n";

		getline(cin, line, ';');
		//���� �� ������������ for � ����������
		for (size_t i = 0; i < line.size(); i++)
		{
			//��������� �������� �� ������ ����������� �������
			if (line[i] == '(' || line[i] == '[' || line[i] == '{')
			{
				//���� �a� �� ���������� � ����
				stack.push(line[i]);
			}


			//� ���� ������ ���������, �������� �� ������ ����������� �������
			else if (line[i] == ')' || line[i] == ']' || line[i] == '}' && !stack.empty() && stack.top() == line[i])
			{
				if (stack.empty() || stack.top() != '(' || stack.top() != '[' || stack.top() != '{') throw bracket_error("������ ����������� �� �����");
				//���� � ������ ����� ����, ������� ��������� ����������� ������ �� �����
				stack.pop();
			}


		}
		cout << "\n������ ����������� �����\n";

	}

	catch (const bracket_error& bracket)
	{
		cout << bracket.what();
	}
	return 0;
}