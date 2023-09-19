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

	string N = "";
	cin >> N;
	
	vector<int> v;

	for (int i = 0; i < N.length(); i++)
	{
		v.push_back(N[i] -48);
	}

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < N.length(); i++)
	{
		cout << v[i];
	}

	return 0;
}