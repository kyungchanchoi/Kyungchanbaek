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

	// 1 ≤ A ≤ B ≤ 10^14
	long long A;
	cin >> A;

	long long B;
	cin >> B;

	// 거의 소수 : 어떤 소수의 N제곱 ( N >= 2 )
	// 최소 2제곱의 수가 A와 B 사이에 있어야 하므로 소수의 범위는 root A 부터 root B 사이다
	// 따라서 root B까지의 소수를 에라토스테네스의 체로 구한다

	const int Max = 10000001;
	long long arr[Max] = { false }; // 10^14의 제곱근 값 + 1

	// 0과 1은 소수가 아니다
	arr[0] = arr[1] = true;

	// 제곱근까지 에라토스테네스의 체
	for (long long i = 2; i <= sqrt(Max); i++)
	{
		// 소수가 아니라면 패스
		if (arr[i] == true) continue;

		// i의 배수를 담은 j를 max의 제곱근까지 늘리고 해당 합성수를 true로 제외시킴
		for (int j = i + i; j < Max; j = j + i)
		{
			arr[j] = true;
		}
	}

	long long count = 0; // 결과를 담을 count변수

	for (long long i = 2; i < Max; i++)
	{
		// 소수 2부터 고른다
		if (arr[i] == false)
		{
			long long Prime = i;
			long long AlmostPrime = Prime;

			// 판별
			while (Prime <= (double)B / AlmostPrime)
			{				
				if (AlmostPrime * Prime  >= A )
				{
					count++;
				}

				AlmostPrime = AlmostPrime * Prime;
			}
		}
	}

	cout << count << "\n";

	return 0;
}