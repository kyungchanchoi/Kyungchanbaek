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

	// 고유번호의 갯수 N
	int N = 0;
	cin >> N;

	// 갑옷이 만들어지는 마법의 수 M
	int M;
	cin >> M;

	// 고유번호의 종류를 vector v에 담기
	vector<int> v;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	// 투 포인터를 사용하여 결과 출력하기
	int counter = 0;
	for (int start = 0; start < N; start++)
	{
		int sum = v[start];

		for (int end = start + 1; end < N; end++)
		{
			sum = sum + v[end];
			if (sum == M)
			{
				counter++;
				break;
			}
			else
			{
				sum = sum - v[end];
			}
		}
	}

	cout << counter;

	return 0;
}