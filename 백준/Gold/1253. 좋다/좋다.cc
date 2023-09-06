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

	int N = 0;
	cin >> N;

	vector<int> v;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		int check = v[i]; // 현재 좋은수인가 아닌가를 판단하려는 인덱스의 수
		
		int start = 0;
		int end = N - 1;
		int sum = 0;

		//  현재 인덱스 i의 수는 건드리면 안되므로 start나 end에 i가 잡히면 넘어가야한다
		while ( start < end )
		{
			sum = v[start] + v[end];

			if (sum > check)
			{
				sum -= v[end];
				end--;
			}
			else if (sum < check)
			{
				sum -= v[start];
				start++;
			}

			else
			{
				if (start == i)
				{
					start++;
				}

				else if (end == i)
				{
					end--;
				}

				else
				{
					counter++;
					break;
				}
			}
		}
	}
	
	cout << counter;

	return 0;
}