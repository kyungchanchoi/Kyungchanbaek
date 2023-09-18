#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare
{
	bool operator() (int n1, int n2)
	{
		int num1;
		if (n1 < 0)	num1 = -(n1);
		else num1 = n1;

		int num2;
		if (n2 < 0) num2 = -(n2);
		else num2 = n2;

		// 절대값이 같다면 
		if (num1 == num2)
		{
			return n1 > n2; // 더 작을 때(음수일때) swap
		}

		else
		{
			return num1 > num2; // 절대값이 작으면 swap
		}

	}
};
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 정수 N개 ( 1 <= N <= 100,000)
	int N = 0;
	cin >> N;

	priority_queue<int, vector<int>, compare> pq;

	// 출력되는 값을 저장할 벡터 r
	vector<int> r;

	// 입력받는 값 x
	int x = 0;

	// N번 입력받는다
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		
		// x가 0일땐 출력
		if (x == 0)
		{
			if (pq.empty() == true) r.push_back(0);
			else
			{
				r.push_back(pq.top());
				pq.pop();
			}			
		}

		// 아닐땐 우선순위큐에 넣어준다
		else
		{
			pq.push(x);
		}

	}

	// 출력
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i] << "\n";
	}

	return 0;
}
