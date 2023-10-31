#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// M부터 N 사이의 소수 구하기
	int M, N;
	cin >> M >> N;

	// 에라토스테네스의 체로 구현한다
	vector<int> v;
	for (int i = 0; i <= N; i++)
	{
		if (i <= 1)
		{
			v.push_back(-1);
		}
		else
		{
			v.push_back(i);
		}
	} // v[idx] = idx, 단 v[0] = -1, v[1] = -1

	for (int i = 2; i <= sqrt(N); i++)
	{
		if( v[i] != -1)
		{
			int select = v[i];

			for (int j = i + 1; j <= N; j++)
			{
				if (v[j] % select == 0)
				{
					v[j] = -1;
				}
			}
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (v[i] != -1)
		{
			cout << v[i] << "\n";
		}
	}

	return 0;
}