#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void QuickSort(vector<int> &v, int start, int pivot);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	int K = 0;
	cin >> K;

	int num = 0;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cout << v[K - 1];

	return 0;
}
