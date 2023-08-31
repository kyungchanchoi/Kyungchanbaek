#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, M = 0;
	cin >> N >> M;

	vector<int> v; // 입력값
	vector<int> s; // 합배열
	vector<int> r; // 출력값
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		if (i == 0) s.push_back(num);
		else
		{
			s.push_back(s[i - 1] + num); // s[i] = s[i-1] + v[i]
		}
	}

		int i, j = 0;

	
	for (int k = 0; k < M; k++)
	{
		cin >> i >> j; // i와 j는 인덱스가 아니라 숫자 범위다. 즉 i가 1이면 첫번째 숫자가 있는 v[0]부터...
		if (i == 1) r.push_back(s[j-1]);
		else r.push_back(s[j-1] - s[i - 2]);
		
	}

	for (int k = 0; k < M; k++)
	{
		cout << r[k] << "\n";
	}
	
	return 0;
}