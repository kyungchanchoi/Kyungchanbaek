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
	// 동전의 종류 N
	int N = 0;
	cin >> N;

	// K원
	int K = 0;
	cin >> K;

	// N종류의 동전의 가격을 담을 vector
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	} // 동전의 가격은 오름차순이고 다음동전은 이전동전의 배수다

	int result = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		// K보다 작은 값이 나오면 그 값으로 나누어 동전의 갯수를 더하고
		if (K >= v[i])
		{
			result += K / v[i];
			// 나머지 금액을 갱신한다
			K = K % v[i];
		}
	}

	cout << result;


	return 0;
}
