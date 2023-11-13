#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(int num);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	// (1 ≤ N ≤ 1,000,000)
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i <= 1003001; i++)
	{
		if (i <= 1)
		{
			v.push_back(-1);
		}
		else
		{
			v.push_back(i);
		}
	}

	for(int i = 0; i <= sqrt(1003001); i++)
	{
		if (v[i] != -1)
		{
			for (int j = i + i; j <= 1003001; j = j + i)
			{
				v[j] = -1;
			}
		}
	}

	vector<int> checkv;
	for (int i = N; i <= 1003001; i++)
	{
		if (v[i] != -1)
		{
			if (check(v[i]) == true)
			{
				cout << v[i];
				break;
			}
		}
	}
		
	return 0;
}
bool check(int num)
{
	int temp = num;
	int digit = 1;
	int cal = 1;
	while (temp / 10 > 0)
	{
		digit++;
		cal *= 10;
		temp /= 10;
	}
	
	int* arr = new int[digit];
	int number = num;
	for (int i = 0; i < digit; i++)
	{
		int x = number / cal;
		arr[i] = x;

		number %= cal;
		cal /= 10;
	}

	int start = 0;
	int end = digit - 1;
	while (start <= end)
	{
		if (arr[start] == arr[end])
		{
			start++;
			end--;
		}
		else
		{
			//cout << num << "응아니야\n";
			delete[] arr;
			return false;
		}
	}

	//cout << num << "맞아\n";
	delete[] arr;
	return true;
}