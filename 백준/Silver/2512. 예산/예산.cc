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

	// 지방의 수, 3 <= N <= 10,000
	int N = 0;
	cin >> N;

	// N개의 지방에서의 예산요청 금액 1 <= num <= 100,000
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	// 총 예산, N <= M <= 1,000,000,000
	int M = 0;
	cin >> M;

	// 우리가 원하는 상한액
	int limit = 0;

	// 상한액을 임의로 정하고 주어진 예산요청금액을 모두 확인한다음
	// 조건에 맞는다면 상한액을 늘려보고
	// 조건에 맞지 않는다면 상한액을 줄여본다

	// v를 오름차순 정렬하여 최소값과 최대값을 구한다.
	sort(v.begin(), v.end());

	// 1을 시작으로 해야한다. 벡터의 최소값을 start로 할 경우 총 예산이 터무니없이 작을 경우 안돌아간다.
	int start = 1;
	// 최대값을 마지막으로 
	int end = v[N - 1];

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int count = 0;
		// 모든 예산에 대하여
		for (int i = 0; i < N; i++)
		{
			if (v[i] <= mid)
			{
				count += v[i];
			}
			else
			{
				count += mid;
			}
		}

		//cout << "start는 " << start << "  end는 " << end << "   mid는 " << mid << "   count값은  " << count << "\n";
		// 총 예산을 넘지 않았다면
		if (count <= M)
		{
			// 조건을 만족했으면 현재 상한액을 일단 저장하고 값을 늘려본다
			if (limit == 0) limit = mid;
			else
			{
				if (limit < mid) limit = mid;
			}


			start = mid + 1;						
		}

		// 총 예산을 넘었다면
		else
		{
			// mid값을 줄여본다
			end = mid - 1;
		}
	}

	// limit가 최대 상환액이 된다.
	cout << limit;



	return 0;
}
