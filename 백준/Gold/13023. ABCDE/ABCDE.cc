#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& v, vector<bool>& visit, int nodenum, int depth, bool &check);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	// N명의 사람, 0번부터 N-1번까지, node
	int N = 0;
	cin >> N;

	// M명의 친구관계, edge
	int M = 0;
	cin >> M;

	// Graph를 이차원벡터를 활요한 인접리스트로 구현
	vector<vector<int>> v(N);
	int a = 0, b = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		cin >> b;

		// 방향 없는 edge로 연결
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// 방문여부를 확인하는 visit 벡터
	vector<bool> visit(N, false); // 0부터 N-1까지의 node이므로 N개로 초기화

	bool check = false;
	for (int i = 0; i < N; i++)
	{
		DFS(v, visit, i, 1, check);

		if (check == true) break;
	}
	
	if( check == true ) cout << "1";
	else cout << "0";
	
	return 0;
}
void DFS(vector<vector<int>>& v, vector<bool>& visit, int nodenum, int depth, bool& check)
{
	// depth가 5라면 1출력 후 종료
	if (depth == 5)
	{		
		check = true;
		return;
	}
	
	else
	{
		// 방문하지 않은 노드라면
		// 방문 체크
		visit[nodenum] = true;

		// 방문하지 않은 다음노드에 방문
		for (int i : v[nodenum])
		{
			if (visit[i] == false)
			{				
				DFS(v, visit, i, depth + 1, check);
			}
		}

		// 돌아왔으니 현재노드 방문체크 해제
		visit[nodenum] = false;
	}
}