#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수열의 크기 N 
	int N = 0;
	cin >> N;

	int num = 0;
	stack<int> st;
	vector<int> v(N, -1);
	int currentidx;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		currentidx = i;

		// 스택이 비어있다면
		if (st.empty() == true)
		{
			st.push(num); // 넣으세요
		}

		// 그게 아니라면
		else
		{
			// 현재 입력한 수보다 스택의 top보다 큰 경우
			if (st.top() > num)
			{
				st.push(num);
			}
			else
			{
				while (st.top() < num) // 입력한 수보다 큰 top이 나올때까지
				{
					// 반복문이 돈다면 해당 top의 오큰수는 num이므로
					if (v[currentidx - 1] == -1) // 오큰수가 저장되어 있지 않을 때만
					{
						v[currentidx - 1] = num; // num을 넣어줌
						st.pop();
						currentidx--;
					}

					else
					{
						currentidx--;
					}

					if (st.empty() == true) break; // 스택이 비어버리면 탈출
				}

				// 오큰수 판별 끝났으면 입력한 수를 스택으로
				st.push(num);
			}	
		}
	}

	// 출력
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}
