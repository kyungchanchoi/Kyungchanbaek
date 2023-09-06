#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool check(vector<int> v, vector<int> c);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S = 0, P = 0;

	// 첫번째 줄
	cin >> S >> P;

	string s = "";

	// 두번째 줄
	cin >>  s;

	// 세번째 줄 : A C G T
	vector<int> v;
	int num = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	int start = 0;
	int end = P;
	int counter = 0;
	vector<int> c(4, 0);

	// 반복 횟수 : S-P+1
	int i = 0;
	while (i <= S - P)
	{
		if (i == 0)
		{
			// 첫 부분 배열의 원소갯수를 벡터 c에 넣어줌
			for (int j = 0; j < P; j++)
			{
				if (s[j] == 'A')
				{
					c[0] = c[0] + 1;
				}
				else if (s[j] == 'C')
				{
					c[1] = c[1] + 1;
				}
				else if (s[j] == 'G')
				{
					c[2] = c[2] + 1;
				}
				else if (s[j] == 'T')
				{
					c[3] = c[3] + 1;
				}
			}

			// 조건을 만족하면 +
			if (check(v, c) == true) counter++;

			i++;
		}

		else
		{
			// 앞 원소 빼기
			if (s[i - 1] == 'A')
			{
				c[0] = c[0] - 1;
			}
			else if (s[i - 1] == 'C')
			{
				c[1] = c[1] - 1;
			}
			else if (s[i - 1] == 'G')
			{
				c[2] = c[2] - 1;
			}
			else if (s[i - 1] == 'T')
			{
				c[3] = c[3] - 1;
			}

			// 뒤 원소 넣기
			if (s[P + i - 1] == 'A')
			{
				c[0] = c[0] + 1;
			}
			else if (s[P + i - 1] == 'C')
			{
				c[1] = c[1] + 1;
			}
			else if (s[P + i - 1] == 'G')
			{
				c[2] = c[2] + 1;
			}
			else if (s[P + i - 1] == 'T')
			{
				c[3] = c[3] + 1;
			}
			// 조건을 만족하면 +
			if (check(v, c) == true) counter++;
			i++;
		}


	}

	cout << counter;

	return 0;
}
bool check(vector<int> v, vector<int> c)
{
	for (int i = 0; i < 4; i++)
	{
		if (v[i] > c[i]) return false;
	}

	return true;
}