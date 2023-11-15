#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1 ≤ min ≤ 1,000,000,000,000  
	// min ≤ max ≤ min + 1,000,000
	ll min, max;

	cin >> min >> max;

	// min에서 max까지 최대 백만이므로 vector의 최대갯수는 백만개이다
	/* ex) min = 1 max = 10
	       v0 = 1, v1 = 2, ... , v9 = v10
		   max - min = 9 => idx : 0 ~ max - min */
	vector<ll> v;
	for (ll i = min; i <= max; i++)
	{
		v.push_back(i);
	} // v[0] = min, v[max-min] = max;
	
	// 백만까지 소수를 에라토스테네스의 체로 구해놓는다
	vector<ll> sosu(1000001, 0);
	sosu[0] = sosu[1] = -1;
	for (ll i = 2; i <= sqrt(1000001); i++)
	{
		if (sosu[i] == -1) continue;

		for (ll j = i + i; j < 1000001; j = j + i)
		{
			sosu[j] = -1;
		}
	}

	// 2부터 max의 제곱근이하의 정수가 제곱수이다
	// 이때 소수만 골라 시간단축한다
	ll temp = v[0];
	for (ll i = 2; i <= sqrt(max); i++)
	{
		if (sosu[i] == -1) continue;

		// 제곱수 X
		ll X = i * i;
	
		// 제곱수로 나누어 떨어지는 가장 가까운 인덱스를 구함
		ll check;
		if (temp % X == 0)
		{
			check = temp % X;
		}
		else check = X - temp % X;
		
		// 배열 내의 모든 값에 대하여
		// v[0] = min, v[max-min] = max;	
		for (ll j = check; j <= max - min; j = j + X)
		{
			if (v[j] == -1) continue;
			
			v[j] = -1;
			
		}
	}

	// 배열 내의 모든 값에 대하여
	ll count = 0;
	for (ll i = 0; i <= max - min; i++)
	{
		if (v[i] != -1)
		{
			//cout << v[i] << " ";
			count++; // -1이 아닐 때 카운팅
		}
	}
	
	cout << count;

	return 0;
}
