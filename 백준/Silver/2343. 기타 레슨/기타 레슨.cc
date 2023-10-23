#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> &A, int n);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 강의의 갯수 N (1 ≤ N ≤ 100,000)
	int N;
	cin >> N;

	// 블루레이의 갯수 M (1 ≤ M ≤ N)
	int M;
	cin >> M;

	// 강의별 길이를 입력받고 벡터에 넣어준다
	vector<int> v;
	int max = 0; // 가장 긴 길이의 강의
	int sum = 0; // 모든 강의의 길이의 합
	for (int i = 0; i < N; i++)
	{
		int minute;
		cin >> minute;

		// 가장 긴 길이의 강의 구하기
		if (max < minute) max = minute;

		// 모든 강의의 길이의 합 구하기
		sum += minute;

		// 어쨌건 강의들을 벡터에 넣어주기
		v.push_back(minute);
	}

	// start를 max로, end를 sum으로 이분탐색함
	int start = max;
	int end = sum;

	while (start <= end)
	{
		
		int mid = (start + end) / 2; // 임의의 블루레이를 시작과 끝의 중간으로 잡음
		
		
		int partsum = 0; // 각 구간별 강의의 길이의 합
		int count = 0; // 블루레이의 갯수 파악

		for (int i = 0; i < N; i++)
		{
			// 부분강의의 합이 블루레이의 크기보다 작으면
			if (partsum + v[i] <= mid)
			{
				partsum += v[i]; // 부분 합 더하기
			}

			else
			{
				partsum = 0; // 부분 합 초기화				
				count++; // 카운팅
				partsum += v[i]; // 이번 것부터 다시 더하기
			}
		}

		if (partsum > 0) count++; // 중간에 0으로 초기화후 마지막 부분까지 남게 되면 카운팅

		
		// 블루레이의 갯수가 입력된 갯수보다 적거나 같다면 조건을 만족하니 일단 블루레이의 크기를 줄여본다
		// 중간값보다 아래범위에서 이분탐색한다
		if (count <= M)
		{
			end = mid - 1;
		}
		// 블루레이의 갯수가 입력된 갯수보다 크다면 조건을 만족하지 않으므로 블루레이의 크기를 늘려야한다
		// 중간값보다 큰범위에서 이분탐색한다
		else 
		{
			start = mid + 1;
		}
	} //  while문을 탈출하면 start > end 이고 이때의 start가 이전의 mid인 답이 된다
	  // mid가 조건을 만족하여 블루레이 크기를 줄이면 end는 무조건 줄어듬
	  // mid가 조건을 만족하지 않아 블루레이 크기를 늘리면서 조건을 만족하는 start가 최소 크기의 블루레이다

	// 출력
	cout << start;

	return 0;
}
