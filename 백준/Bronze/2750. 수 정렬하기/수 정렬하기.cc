#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void swap(int& a, int& b);
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
	vector<int> v;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	// Bubble Sort
	for (int j = N-1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (v[i] > v[i+1])
			{
				swap(v[i], v[i+1]);
			}
		}
	}

	// 출력
	for(int i = 0 ; i < N; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}