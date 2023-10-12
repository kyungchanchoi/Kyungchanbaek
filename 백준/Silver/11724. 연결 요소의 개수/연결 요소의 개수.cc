#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>> &G, vector<int> &visit, int v);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; // 노드의 갯수 N
	int M = 0; // 엣지의 갯수 M

	cin >> N;
	cin >> M;

	// 이차원 벡터로 그래프를 표현
	vector<vector<int>> G(N+1);

	// idx 1부터 N까지 사용, idx는 노드를 뜻하며 원소값은 방문여부(0은 미방문, 1은 방문)
	vector<int> visit(N+1, 0); 

	// edge의 양끝 u와 v
	int u = 0, v = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> u;
		cin >> v;

		// 벡터를 이용해 각 노드간의 엣지를 연결 - 무방향 그래프
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int count = 0; // DFS 반복횟수 = connected component 갯수

	int nodenumber = 1; // 시작 노드는 1
	while (nodenumber <= N)
	{
		if (visit[nodenumber] == 0)
		{
			DFS(G, visit, nodenumber);
			count++; // DFS가 마무리되므로 count + 1
		}

		nodenumber++;
	}
	
	// 출력
	cout << count;
	
	return 0;
}
void DFS(vector<vector<int>> &G, vector<int> &visit, int v)
{
	// 이미 방문한 노드라면 종료
	if (visit[v] == 1)
	{
		return;
	}

	// 그렇지 않다면
	else
	{
		// 방문한 노드가 되므로 방문체크
		visit[v] = 1;
			
		// 방문시 출력
		//cout << v << " ";

		// 연결된 다른 노드를 방문
		for (int i : G[v])
		{
			DFS(G, visit, i);
					
		}
	}
}