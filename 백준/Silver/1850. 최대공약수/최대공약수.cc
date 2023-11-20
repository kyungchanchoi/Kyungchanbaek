#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력되는 자릿수는 최대 2^63 - 1
	ll a, b;
	cin >> a >> b;

	ll big, small = 0;
	if (a > b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}

	ll cal = 0;
	while (true)
	{
		cal = big % small;
		if (cal == 0) break;
		else
		{
			big = small;
			small = cal;
		}
	}
	
	for (int i = 0; i < small; i++)
	{
		cout << 1;
	}

	return 0;
}