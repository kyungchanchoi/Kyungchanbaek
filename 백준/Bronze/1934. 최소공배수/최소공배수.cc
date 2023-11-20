#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;

	vector<int> v;
	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;

		// 유클리드 호제법
		int big = max(a, b);
		int small = min(a, b);
		int result = 0;
		while (true)
		{
			result = big % small;
			if (result == 0) break;
			else
			{
				big = small;
				small = result;
			}
		}

		// 최소공배수를 구한다
		int ans = (a / small) * (b / small) * small;
		
		// 값을 벡터에 저장
		v.push_back(ans);
	}

	// 출력
	for (int i = 0; i < t; i++)
	{
		cout << v[i] << "\n";
	}	

	return 0;
}