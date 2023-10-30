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

	// 카드 묶음의 수 (1 ≤ N ≤ 100,000)
	int N = 0;
	cin >> N;

	// 카드가 한묶음이면 그 묶음이 답이다
	if (N == 1)
	{
		int num;
		cin >> num;
		cout << 0; // 카드묶음이 한개라면 비교를 할 필요 없으니 0을 출력한다 - 틀린 부분
	}

	// 2개 이상의 카드 묶음들
	else
	{
		priority_queue<int, vector<int>, greater<>> pq;
		// 우선순위큐에 삽입
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			pq.push(num);
		}

		int currentcompare = 0; // 현재 단계의 카드묶음의 비교 카운트
		int totalcompare = 0; // 누적 카드묶음의 비교 카운트

		// 모든 카드묶음에 대하여
		while (true)
		{
			// 첫번째 카드뭉탱이를 고른다
			int card1 = pq.top();
			pq.pop();

			// 두번째 카드뭉탱이를 고른다
			int card2 = pq.top();
			pq.pop();

			// 둘이 합치며 카드묶음 비교횟수를 카운트한다
			currentcompare = card1 + card2;
			totalcompare += currentcompare;

			// 골랐던 뭉탱이들을 빼고 난 나머지 카드묶음들이 존재하지않다면 모든 카드묶음을 합친것이니 종료
			if (pq.empty() == true) break;
			else pq.push(currentcompare); // 그렇지 않다면 합친 카드뭉탱이를 우선순위 큐에 넣어준다
		}

		cout << totalcompare; // 누적 비교횟수를 출력한다
	}
	return 0;
}
