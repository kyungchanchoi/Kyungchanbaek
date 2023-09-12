#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> r;
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 수열의 갯수 N
	int N = 0;
	cin >> N;

	// 수열을 이루는 N개의 숫자들
	int num = 0;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	
	vector<char> result;
	stack<int> st;
	int count = 0;

	for (int i = 1; i <= N; i++) // 스택에는 1부터 n까지 오름차순으로 넣는다
	{		
		// 1. 스택에 i를 넣는다
		st.push(i);
		result.push_back('+');
		
		// top을 확인하고 v[count]의 값과 같다면 pop해준다
		while ( st.empty() == false )
		{
			if (st.top() == v[count])
			{
				st.pop();
				result.push_back('-');
				count++;
			}

			else break;
		}
	}

	
	// 출력
	if ( count != N ) // v 원소값이 아직 남아있다면
	{
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}


	return 0;
}
