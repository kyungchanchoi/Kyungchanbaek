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
	// 동전의 종류 N
	int N = 0;
	cin >> N;

	// K원
	int K = 0;
	cin >> K;

	// N종류의 동전의 가격을 담을 vector
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	} // 동전의 가격은 오름차순으로 주어짐

	int result = 0;
	for(int i = N-1; i>= 0; i--)
	{
		int count = 0; // 동전의 갯수
		int idx = i; // 마지막 인덱스부터 빼본다

		int calK = K;

		while (idx >= 0)
		{
			// 현재 상황에서 최선의 선택을 한다
			// 뺄 수 있는 가장 큰 금액을 뺀다
			if (calK >= v[idx])
			{
				calK -= v[idx];
				count++;
			}

			// 뺄 수 없다면 그 다음 금액으로 넘어간다
			else
			{
				idx--;
			}		
		}
		// 반복문을 완료했을 때 돈이 남았으면 안된다
		if (calK == 0)
		{
			if (result == 0) result = count;
			else
			{
				if (result > count) result = count;
			}
			
		}
	}

	cout << result;


	return 0;
}
