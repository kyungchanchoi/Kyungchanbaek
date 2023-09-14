#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> card;

	int N = 0; // 정수 N 초기화

	cin >> N; // 정수 N 입력받기 및 예외처리
	if (N < 1 || N > 500000) return 0;

	for (int i = 0; i < N; i++)
	{
		card.push(i + 1);
	}

	int temp = 0;
	while (card.size() > 1)
	{
		card.pop(); // 맨 앞 카드 제거
		temp = card.front();
		card.pop();
		card.push(temp);
	}

	cout << card.front();
	
	return 0;
}
