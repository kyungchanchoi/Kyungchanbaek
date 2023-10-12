#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int number, int count, int N);
bool checkPrimeNumber(int num);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; // N자리 수
	cin >> N; // 1 <= N <= 8

	

	for (int i = 2; i < 10; i++)
	{
		if (checkPrimeNumber(i) == true)
		{
			DFS(i, 1, N);
		}		
	}


	return 0;
}
void DFS(int number, int count, int N)
{
	// 마지막 확인 후 출력 후 DFS 종료
	if (count == N )
	{
		// number가 소수라면
		if (checkPrimeNumber(number))
		{
			cout << number << "\n";
		}
		return;
	}
	else
	{		
		// number가 소수라면 아랫자리수 하나 늘리고 DFS
		if (checkPrimeNumber(number))
		{
			number = number * 10; 
			count++;

			int i = 1;
			while (i < 10)
			{
				// 2로 나눠지는 수는 소수가 아니므로 2로 나눠지는 수는 빼고 더한다
				if (i % 2 != 0)
				{
					DFS(number + i, count, N);
				}
				i++;
			}						
		}

		// number가 소수가 아니라면
		else return;
	}
}
bool checkPrimeNumber(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0) return false;
	}

	return true;
}