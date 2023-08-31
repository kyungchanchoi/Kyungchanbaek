#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M = 0; 
	cin >> N >> M;

	vector<vector<int>> s;
	vector<int> v; // 각 행의 배열
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			// 각 행의 합배열
			if (j == 0) v.push_back(num);
			else v.push_back(v[j - 1] + num);
		}
		s.push_back(v);
		v.clear();
	}
		
	int result = 0;
	int a, b, c, d = 0;
	vector<int> r;

	for (int i = 0; i < M; i++)
	{			
		cin >> a >> b >> c >> d;

		int num1 = a - 1;
		int num2 = b - 1;
		int num3 = c - 1;
		int num4 = d - 1;

		// 첫번째 좌표의 열이 1일때
		if (num2 == 0)
		{
			for (int j = num1; j <= num3; j++)
			{
				result += s[j][num4];				
			}
			r.push_back(result);
			result = 0;
		}

		// 그렇지 않을때
		else
		{
			for (int k = num1; k <= num3; k++)
			{
				result += s[k][num4] - s[k][num2-1];			
			}
			r.push_back(result);
			result = 0;
		}		
	}
	
	for (int i = 0; i < M; i++)
	{
		cout << r[i] << "\n";
	}

	return 0;
}