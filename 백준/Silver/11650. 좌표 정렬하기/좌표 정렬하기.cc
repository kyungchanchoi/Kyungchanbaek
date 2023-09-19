#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> x, pair<int, int> y)
{
	// 두 좌표의 x좌표가 같을 경우
	if (x.first == y.first)
	{
		return x.second < y.second; // y좌표가 큰 순으로 정렬
	}
	
	else
	{
		return x.first < y.first; // x좌표가 큰 순으로 정렬
	}
}
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 좌표의 갯수 N (1 ≤ N ≤ 100,000)
	int N = 0;
	cin >> N;

	// 좌표 입력 : 좌표는 pair를 사용하는걸로
	//  (-100,000 ≤ xi, yi ≤ 100,000) 
	int x = 0, y = 0;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;

		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), compare);

	// 출력
	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}