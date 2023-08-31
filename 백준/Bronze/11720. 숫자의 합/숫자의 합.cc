#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int N = 0;
	string s = "";
	int result = 0;

	cin >> N >> s;

	for (int i = 0; i < N; i++)
	{
		result += s[i] - 48;

	}

	cout << result;
	
	return 0;
}