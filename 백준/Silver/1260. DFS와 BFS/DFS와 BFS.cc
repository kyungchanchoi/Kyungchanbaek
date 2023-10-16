#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& G, vector<bool>& visit, int V);
void BFS(vector<vector<int>>& G, vector<bool>& visit, queue<int>& q, int V);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 노드의 갯수 N : 1 ~ 1,000
	int N = 0;
	cin >> N;

	// 엣지의 갯수 M : 1 ~ 10,000
	int M = 0;
	cin >> M;

	// V는 시작점
	int V = 0;
	cin >> V;

	// 벡터를 활용한 인접리스트로 그래프를 구현
	// 노드는 1번부터 N번까지 사용하므로 N+1의 공간으로 구현
	vector<vector<int>> G(N+1);
	// M개의 엣지이므로 M번 시작과 끝을 입력받고 양방향으로 연결
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		// 양방향 연결
		G[s].push_back(e);
		G[e].push_back(s);
	}

	// 가장 작은 노드부터 방문해야하므로 모든 노드에 대하여 인접 노드를 오름차순으로 정렬
	for (int i = 1; i < N+1; i++)
	{
		sort(G[i].begin(), G[i].end());
	}
	// 방문 배열 visit은 false로 초기화 -> 1부터 N까지의 노드
	vector<bool> visit(N + 1, false);
	
	// V부터 시작하여 DFS
	DFS(G, visit, V);



	// 한줄 띄우기
	cout << "\n";


	// Queue를 선언하여 BFS 시작
	queue<int> q;

	// 방문 배열 visit은 false로 초기화 -> 1부터 N까지의 노드
	vector<bool> visit2(N + 1, false);

	// BFS
	BFS(G, visit2, q, V);

	return 0;
}
void DFS(vector<vector<int>>& G, vector<bool>& visit, int V)
{
	// 이미 방문한 노드라면
	if (visit[V] == true)
	{
		return; //  종료
	}

	else
	{
		// 방문했으니 체크
		visit[V] = true;

		// 방문 출력
		cout << V << " ";
		
		// V의 인접 노드에 대하여
		for (int i : G[V])
		{
			// 방문한 노드가 아니라면
			if (visit[i] == false)
			{
				DFS(G, visit, i); // 방문하세요
			}
		}
	}
}
void BFS(vector<vector<int>>& G, vector<bool>& visit2, queue<int>& q, int V)
{
	q.push(V);
	visit2[V] = true;

	// 큐가 비어질때 까지 돌린다
	while (q.empty() != true)
	{
		// 큐의 맨 앞은 방문하는 노드
		int currentNode = q.front();
		cout << currentNode << " "; // 방문했으니 출력

		q.pop(); // 방문한 노드를 처리했으니 빼주고

		// 방문한 노드의 인접 노드에 대해
		for (int i : G[currentNode])
		{
			// 방문하지 않은 노드라면
			if (visit2[i] == false)
			{
				q.push(i); // 큐에 넣어준다
				visit2[i] = true; // 방문했으니 체크
			}
		}
	}
}