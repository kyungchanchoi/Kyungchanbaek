#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 사람의 수 N(1 ≤ N ≤ 1,000)
	int N = 0;
	cin >> N;

	// 인출시간 P (1 ≤ Pi ≤ 1, 000)
	int P = 0;
	vector<int> v;
	
	for (int i = 0; i < N; i++)
	{
		cin >> P;
		v.push_back(P);
	}

	sort(v.begin(), v.end());

	// 결과를 위한 인출시간 계산
	int count = N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += v[i] * count;
		count--;
	}

	cout << sum;

	return 0;
}