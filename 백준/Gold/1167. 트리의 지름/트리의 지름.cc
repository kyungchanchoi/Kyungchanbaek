#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(vector<vector<pair<int, int>>>& G, int V, int& result, int& start);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 노드의 갯수 V ( 2 <= V <= 100,000 )
	int V = 0;
	cin >> V;

	vector<vector<pair<int,int>>> G(V + 1);
	for (int i = 1; i <= V; i++)
	{
		// 현재 노드 입력
		int currentnode;
		cin >> currentnode;

		int node = 0;
		int edge = 0;

		// 연결된 모든 노드 입력
		while ( true )
		{
			// 연결된 노드 입력
			cin >> node;

			// -1이라면 더이상 연결된 노드가 없으니 종료
			if (node == -1) break;
			
			// 그렇지 않다면 edge의 가중치 입력
			cin >> edge;

			// pair로 연결된 노드와 가중치를 연결해줌
			G[currentnode].push_back(make_pair(node, edge));
		}
	}

	int result = 0;

	int maxnode = 1;
	BFS(G, V, result, maxnode);
	
	BFS(G, V, result, maxnode);

	cout << result;

	return 0;
}
void BFS(vector<vector<pair<int, int>>>& G, int V, int& result, int& start)
{
	vector<int> visit(V + 1, -1); // edge가 0이면 곤란하니까 -1로 초기화한다

	queue<pair<int,int>> q; // pair로 연결된 노드와 엣지의 가중치를 넣어준다

	q.push(make_pair(start,0)); // 노드 1부터 시작
	visit[start] = 0; // 첫 이동거리는 0이다

	int maxnode = 0; // 이동거리의 최대값이 갱신될 때의 node값
	int maxedge = 0; // 이동거리의 최대값이 갱신될 때의 edge값
	while (q.empty() != true)
	{
		int currentnode = q.front().first; // 방문한 노드
		int edge = q.front().second; // 방문한 노드까지의 거리를 뜻한다

		q.pop(); // 큐의 맨 앞의 값을 저장했으니 pop해주고 작업한다

		// G에 (노드번호,가중치)를 저장했으니 pair p에 현재 방문한 노드와 연결된 pair들을 담아준다
		for (pair<int,int> p : G[currentnode])
		{
			// 연결된 노드가 아직 방문하지 않았다면
			if (visit[p.first] == -1)
			{
				// 여태까지의 이동거리 edge에 연결된 노드의 가중치를 더해서 방문체크
				visit[p.first] = edge + p.second;
				// 이후에 pair로 묶어 큐에 저장한다
				q.push(make_pair(p.first,visit[p.first]));
				
				// 큐에 저장시 최대 이동거리가 갱신되면 max에 저장
				if (maxedge < visit[p.first])
				{
					maxnode = p.first;
					maxedge = visit[p.first];
				}
			}
		}
	}

	// 참조된 result에 max를 넣어준다
	result = maxedge;
	start = maxnode;
}

