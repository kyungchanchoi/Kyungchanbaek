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

	// N은 최대 1천만 -> nlogn도 2억이 넘어가서 gg -> O(kn)인 radixsort를 사용
	int N = 0;
	cin >> N;

	// 입력받는 수는 1만보다 작거나 같은 자연수이므로 인덱스 1부터 10000까지 사용 
	int num = 0;
	vector<int> v(10001,0);

	// data 입력
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v[num]++;
	}

	// 출력
	for (int i = 1; i < 10001; i++)
	{
		if (v[i] > 0)
		{
			for (int j = 0; j < v[i]; j++)
			{
				cout << i << "\n";
			}
		}	
	}

	return 0;
}
