#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str = "";
	getline(cin, str);


	// 첫 숫자 : 양수
	int num = stoi(str.substr(0, 5));

	// 첫 -가 올때까지 더함
	while (1)
	{
		if (str.find("+") < str.find("-"))
		{
			// +
			str = str.substr(str.find("+") + 1);
			num += stoi(str.substr(0, 6));
		}
		else break;
	}

	// a - b ....
	// 뒤에 연산자가 없으면 종료

	while (1)
	{
		if (str.find("+") == str.npos)
		{
			if (str.find("-") == str.npos)
			{
				cout << num;
				return 0; // 그럼 끝
			}
			else
			{
				str = str.substr(str.find("-") + 1);
				num -= stoi(str.substr(0, 6));
			}
		}
		else if (str.find("-") == str.npos)
		{
			if (str.find("+") == str.npos)
			{
				cout << num;
				return 0; // 그럼 끝
			}
			else
			{
				str = str.substr(str.find("+") + 1);
				num -= stoi(str.substr(0, 6));
			}
		}
		else
		{
			if (str.find("+") < str.find("-"))
			{
				// +
				str = str.substr(str.find("+") + 1);
				num -= stoi(str.substr(0, 6));
			}
			else
			{
				str = str.substr(str.find("-") + 1);
				num -= stoi(str.substr(0, 6));
			}
		}
	}

}
