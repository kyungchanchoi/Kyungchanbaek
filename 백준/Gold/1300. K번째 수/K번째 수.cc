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

	// 배열의 크기 N (N은 10^5보다 작거나 같은 자연수)
	int N = 0;
	cin >> N;

	// 일차원 배열에서의 k
	int k = 0;
	cin >> k;
	
	// 문제의 해결방식
	// B[k] = x 라고 하면 x보다 작거나 같은(A배열에서 같은 값이 (2,1) (1,2)는 원소값이 같으므로) 
	// 값이 k개여야 한다.
	// 즉 x보다 작거나 같은 값의 갯수를 파악하기 위해
	// x를 mid로 이분탐색한다.

	// 1,1부터 값을 파악해야하므로 start는 1
	int start = 1;
	// N*N 배열에서 가장 큰 수는 N*N이고 나머지 수는 N*N보다 작기 때문에
	// B배열의 k번째 수를 임의로 지정할때 그 수는 k보다 작거나 같을 수 밖에 없다.
	// 따라서 임의의 수를 k까지 봐준다
	int end = k;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		// 임의의 수 mid에 대하여 1행부터 N행까지 mid보다 작은거나 같은 수의 갯수는
		// mid / i이다. i행의 원소는 i, 2i, 3i ... ni까지 가므로
		// 어떤 수 mid가 2i라면 mid / i = 2이고 어떤 수 mid가 2i + a 라면, 즉 mid / i를 하면 2 하고 나머지가 나오게 될 것이다.
		// 예를 들어 mid = 7, i = 3 ... mid/i = 2 ... 1, 즉 i=3 행에서 7보다 작거나 같은 수의 갯수는 2개다
		
		int count = 0; // mid보다 작거나 같은 수를 누적한다
		for (int i = 1; i <= N; i++)
		{
			if (mid / i > N)
			{
				count += N;
				// 각 행마다 N개씩 있으므로 N개를 초과하면 안된다.
				// N= 4, mid = 6이라고 1행에 6보다 작은 원소를 6개 추가하면 안되고 4개 추가해야한다. 
			}
			else
			{
				count += mid / i;
			}
		}

		// k보다 작거나 같다면 
		if (count < k)
		{
			start = mid + 1; // mid의 범위를 더 크게 해서 mid보다 작거나 같은 값을 늘린다(= k를 늘린다)
		}
		else
		{
			end = mid - 1;
		}
	}

	// 출력
	cout << start;

	return 0;
}
