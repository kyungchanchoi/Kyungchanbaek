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

	// 자연수 n (1 ≤ n ≤ 10^12)
	ll n;
	cin >> n;

	// 백만까지 소수를 구한다
	vector<ll> sosu(1000001,false);
	sosu[0] = sosu[1] = true;
	// 에라토스테네스의 체
	for(ll i = 2; i <= sqrt(1000001); i++)
	{
		if(sosu[i] == true) continue;
	
		for (ll j = i + i; j < 1000001; j = j + i)
		{
			sosu[j] = true;
		}
	} // i가 소수라면 sosu[i] = false이다

	/*
	// 오일러 피
	for (ll i = 2; i <= n; i++)
	{
		if (P[i] == i)
		{
			if (sosu[i] != -1)
			{
				ll currentK = i;
				for (ll k = currentK; k <= n; k = k + currentK)
				{
					P[k] = P[k] - P[k] / currentK;
				}
			}	
		}	
	}*/

	ll temp = n;
	vector<ll> store;
	ll idx = 0;
	// N = a * b일때 a와 b 둘다 N의 제곱근보다 클 수 없다
	// 즉 N의 제곱근까지 나누어지는 수가 없다면 N은 소수다
	while ( true )
	{		
		// temp 확인용 체크
		ll check = temp;

		// n을 n의 제곱근까지의 소수로 쭉 나누어본다. 나눠지면 그건 소인수 
		for (ll i = 2; i <= sqrt(n); i++)
		{
			if (temp % i == 0)
			{
				// 이미 저장되어있는 소인수인지 확인
				if (idx != 0)
				{
					if (i != store[idx - 1])
					{
						store.push_back(i);
						idx++;
					}
				}	
				// 그게 아니고 처음이라면 그냥 저장
				else
				{
					store.push_back(i);
					idx++;
				}

				temp = temp / i;
				break;
			}
		}	

		// temp가 1이라면 더이상 나눠지는 소수가 없으므로 종료
		if (temp <= 1) break;

		// 그게 아니라면 for문 다 돌렸는데 temp가 그대로라면 그 temp는 소수인 것인다
		else if (temp == check)
		{
			store.push_back(temp);
			break;
		}
	}

	ll Pn = n;
	for (ll i = 0; i < store.size(); i++)
	{
		Pn = Pn - Pn / store[i];
	}

	// count만큼 횟수를 돌렸는데도 값이 그대로면 그건 소수다
	if (Pn == n)
	{
		if (Pn == 1) cout << Pn;
		else Pn = n - 1;
	}

	else cout << Pn;

	return 0;
}
