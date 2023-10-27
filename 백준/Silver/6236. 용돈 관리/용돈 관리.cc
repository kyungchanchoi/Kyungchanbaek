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

	// 버틸 날 N (1 ≤ N ≤ 100,000)
	int N = 0;
	cin >> N;

	// 돈을 뺄 횟수 M (1 ≤ M ≤ N)
	int M = 0;
	cin >> M;

	// 현우가 i번째 날에 이용할 금액 (1 ≤ 금액 ≤ 10000)
	vector<int> v;
	int sum = 0;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);

		sum += v[i];

		if (max == 0) max = v[i];
		else
		{
			if (max < v[i]) max = v[i];
		}
	}

	// 임의의 돈 k원을 인출하고
	// 그날의 지출이 k원 아래라면 k원에서 차감하면 된다
	// 모자라면 남은 돈을 다 넣고 돈 뺀 횟수를 +1 하고 k원을 뺀다
	// k의 최소금액을 이분탐색으로

	int start = 0; // 최소 금액은 0원
	int end = sum; // 최대범위는 모든 금액의 합으로 한다 그래야 한번만 뽑고 모든 날을 쓸 수 있는 경우도 챙기기 때문이다

	int mink = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		//cout << "start : " << start << "   end : " << end << "   mid : " << mid << "\n";

		int current = mid; // k원 뽑았다
		int count = 1; // 돈 뺀 횟수 - 처음에 한번 빼고 시작한다
		bool over = false; // 인출했는데도 돈이 모자르면 안된다

		// 하루마다 계산
		for (int i = 0; i < N; i++)
		{
			int today = v[i]; // 오늘 쓸 돈
			if (today > mid) // 인출금액과 오늘 쓸 돈 비교
			{
				over = true; 				
				// 내가 놓친 부분 : 인출가능한 돈을 넘었다면 over을 true해주고 이분탐색 범위를 늘려준다.
				// 문제를 해석할 때 돈이 모자르면 인출한 돈으로 생활한다를 하루마다 쓸 돈을 배제하고 인출한 돈으로만 해결한다로
				// 잘못 해석해서 나온 결과이다. 문제 잘 해석하기
			}
			
			if (today <= current)
			{
				current -= today; // 현재 빼놓은 돈에서 쓴다
			}
			else
			{
				current = mid; // 남은 돈 다 넣고 다시 뺀다
				current -= today; // 오늘건 써야지 -> 맨 처음 구현할땐 써놓고 놓친 부분
				count++; // 뺀 횟수 추가
			}
		}

		//cout << "총 count는 : " << count << "\n\n\n";

		// 인출금액이 하루를 감당할 수 없다면
		if (over == true)
		{
			// 늘린다
			start = mid + 1; 
		}
		// 감당 가능하고 돈을 뽑은 횟수가 M번보다 작거나 같다면
		else if (count <= M)
		{
			if (mink == 0) mink = mid;
			else
			{
				if (mink > mid)
				{
					mink = mid;
				}
			}

			// 뽑는 돈 k를 줄여본다 최소값찾기이므로
			end = mid - 1;

		}
		// 조건을 만족하지 않으면 늘린다
		else start = mid + 1;
	}

	cout << mink;

	return 0;
}
