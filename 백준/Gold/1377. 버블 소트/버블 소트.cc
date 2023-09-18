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

	// N개의 수 
	int N = 0;
	cin >> N;

	// data 입력
	int num = 0;
	vector<pair<int,int>> v;
	
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(make_pair(num, i));
	}

	sort(v.begin(), v.end()); // O(nlogn)

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < v[i].second - i) max = v[i].second - i;
	}
	
	cout << max + 1;


	return 0;
}