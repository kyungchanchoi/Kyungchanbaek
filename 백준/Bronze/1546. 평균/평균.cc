#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N = 0;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		v.push_back(num);
	}

	int Max = 0;
	for (int i = 0; i < N; i++)
	{
		if (Max < v[i]) Max = v[i];
	}

	double total = 0.00;
	for (int i = 0; i < N; i++)
	{
		total += (double)v[i] / Max * 100;
	}

	cout << total / N;
}