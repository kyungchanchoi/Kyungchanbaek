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

	int N, M = 0; 
	cin >> N >> M;

	vector<int> v; // 원본 배열
	long num = 0;
	vector<long> s; // 합 배열
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);

		if (i == 0) s.push_back(num);
		else s.push_back(s[i - 1] + num);
	}

	// 문제 : A(i)부터 A(j)까지의 합이 M으로 나누어 떨어지는 (i,j)의 갯수 구하기
	// (S[j] - S[i-1]) % M = 0
	// S[j] % M = S[i-1]) % M
	// 합 배열은 각 구간의 합임
	// 그리고 각 구간의 나머지 연산을 더한 값의 나머지 연산값은 각 구간을 모두 합한 값의 나머지 연산값과 같음
	// 그러므로 나머지 연산을 미리 하고 각 구간을 합쳐서 나머지 연산을 하면 된다 이말이야. 그러면 각 구간을 합치는 경우의 수를 구하면 그게 답이다
	// 따라서 합 배열을 나머지 연산을 미리 연산하고 나머지가 같은 경우의 수를 합치면 답이다
	vector<long> m;
	for (int i = 0; i < N; i++)
	{
		m.push_back(s[i] % M);
	}

	// (S[j] - S[i-1]) % M = 0 => 1. 합 배열의 나머지값이 0인 친구들은 그 자체로 답이므로 답에 포함시킨다. 
	// S[j] % M = S[i-1]) % M => 2. 그 다음 나머지 값이 같은 애들끼리 조합해야하므로 나머지값 종류 배열을 만든다.
	// 합 배열의 나머지 연산값이 같은 애들끼리 모아놓는 경우의 수를 나머지값 종류 배열로 조합한 후 결과값에 더하자
	
	vector<long> c; // 나머지 값의 종류
	for (int i = 0; i < N; i++)
	{
		// 첫번째 값은 그냥 넣기
		if (i == 0) c.push_back(m[i]);
		// 그 다음부터 값이 다른 경우에만 넣기
		else
		{
			// 벡터 내에 나머지값이 없다면 추가
			if (find(c.begin(), c.end(), m[i]) == c.end()) c.push_back(m[i]);
		}
	}

	long result = 0;
	for (int i = 0; i < c.size(); i++)
	{
		long counter = 0;

		for (int j = 0; j < N; j++)
		{
			if (m[j] == c[i]) counter++;
		}

		// c[i] = 0, 그 구간만으로도 답이므로 +
		if (c[i] == 0) result += counter;

		result += counter * (counter - 1) / 2;
	}

	 cout << result;

	return 0;
}