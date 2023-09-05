#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	int result = 0;

	for (int start = 1; start <= N; start++)
	{
		int sum = start;
		if (start == N)
		{
			result++;
			break;
		}
		for (int end = start + 1; end <= N; end++)
		{
			sum += end;
			if (sum >= N)
			{
				if (sum == N) result++;		

				break;
			}
		}
	}

	cout << result;

	return 0;
}