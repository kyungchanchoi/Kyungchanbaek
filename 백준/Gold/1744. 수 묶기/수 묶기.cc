#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수열은 N개의 수로 구성 (1<= N <=50)
	int N = 0;
	cin >> N;

	// 중복된 수가 나올 수 있다 [ ex) N= 2, {1,1} ]
	// 오름차순 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> pq_minus;
	priority_queue<int, vector<int>, less<int>> pq_plus;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num <= 0) pq_minus.push(num);
		else pq_plus.push(num);
	}

	// 최대값이 나오려면 어떻게 해야하는가?
	// 1. +1은 묶지 않고 더한다
	// 2. +2부터는 가장 큰 수 두 개씩 묶는다
	// 3. 다 묶고 양수가 1개 남았다면 그건 더한다
	// 4. 음수의 갯수가 짝수라면 가장 작은 애들 2개씩부터 묶는다
	// 5. 홀수일 경우에 0이 수열에 있다면 둘이 묶어 지울 수 있음
	// 6. 음수가 한개라도 홀수이므로 5번 조건에 포함가능
	
	
	// 한번 이용된 숫자는 다시 사용하지 않으므로 큐의 탑을 받고 pop해주며 진행한다
	long total = 0;
	// 0을 포함한 음수 파트
	while (pq_minus.empty() != true)
	{
		int num1 = pq_minus.top();
		pq_minus.pop();
		
		// 뽑았는데 이제 더 뽑을게 없다면 어쩔수없이 더한다
		if (pq_minus.empty() == true)
		{
			total += num1;
		}
		// 그게 아니라면 그 다음걸 뽑고 둘이 곱한다. 음수끼리 곱하던 0을 포함해서 곱하던 무조건 최대값이다
		else
		{
			int num2 = pq_minus.top();
			pq_minus.pop();

			total += num1 * num2;
		}		
	}

	// 양수 파트
	while (pq_plus.empty() != true)
	{
		int num1 = pq_plus.top();
		pq_plus.pop();

		// 뽑았는데 이제 더 뽑을게 없다면 어쩔수없이 더한다
		if (pq_plus.empty() == true)
		{
			total += num1;
		}
		// 그게 아니라면 그 다음껄 뽑는다.
		else
		{
			int num2 = pq_plus.top();
			pq_plus.pop();

			// 첫번째로 뽑은 수가 1보다 클 때
			if (num1 > 1)
			{
				// 두번째 수도 1보다 크면
				if (num2 > 1)
				{
					// 곱한다
					total += num1 * num2;
				}
				else
				{
					// 아니면 더한다
					total += num1 + num2;
				}
			}
			// 첫번째로 뽑은 수도 1이면
			else
			{
				// 더한다
				total += num1 + num2;
			}

		}
	}

	cout << total;

	return 0;
}
