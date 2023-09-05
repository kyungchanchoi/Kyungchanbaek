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

	int start = 1;
	int end = 1;

	int sum = 1; // 자연수 1부터 시작
	int count = 0;
	while (1)
	{
		if (start == N) // 
		{
			count++;
			break;
		}
		
		if (sum < N) // sum이 N보다 작다면 end를 뒤로 한칸 옮기고 값 더해줌
		{
			end++;
			sum = sum + end; 		
		}
		else if (sum > N) // sum이 N보다 크다면 현재 start의 값을 빼고 start를 뒤로 한칸 옮겨줌
		{
			sum = sum - start;
			start++;
		}
		else // sum이 N과 같다면 일단 결과값 하나 올려주고 end를 뒤로 한칸 옮기고 값 더해줌
 		{
			count++;
			end++;
			sum = sum + end;		
		}
	}


	cout << count;

	return 0;
}