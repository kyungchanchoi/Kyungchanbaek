#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(vector < vector<int>>& G, int N, int M, int& count);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 도착점 (N, M) (2 ≤ N, M ≤ 100)	
	int N = 0;
	int M = 0;
	cin >> N >> M;

	
	// 미로의 크기도 N개의 줄마다 M개의 원소로 표현
	// 벡터를 활용한 그래프로 표현
	
	vector<vector<int>> G(N+1);
	for (int i = 1; i < N+1; i++)
	{
		string line;
		cin >> line;

		G[i].push_back(0); // 0번째 idx는 사용하지 않음
		for (int j = 0; j < M; j++)
		{
			G[i].push_back(line[j] - 48);
		}
	}
	
	int count = 0;
	BFS(G, N, M, count);

	cout << count;

	return 0;
}
void BFS(vector < vector<int>>&G, int N, int M, int &count)
{
	// 방문 체크
	vector<vector<int>> visit(N+1);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			visit[i].push_back(0);
		}
	}

	// 페어로 좌표를 넣어줌
	queue<pair<int,int>> q;

	// (1,1)부터 시작
	q.push(make_pair(1,1));
	visit[1][1] = 1;
	
	int divide = 0; // 분기점이 생기면 그만큼 count값을 빼줘야함

	while (q.empty() != true)
	{
		int currentX = q.front().first;
		int currentY = q.front().second;

		q.pop();				

		// 큐에 새로 삽입할라는 놈이 N,M이면 종료
		if (currentX == N)
		{
			if (currentY == M)
			{
				count = visit[currentX][currentY];
				
				return;
			}
		}

		// 상하좌우 확인 후 큐에 삽입
		// 상 : 위로 이동시 좌표가 0 이상이어야 하고, 방문을 하지 않았으며, 해당 좌표값이 1이라면 가능
		if (currentX - 1 > 0)
		{
			if (G[currentX - 1][currentY] == 1)
			{
				if (visit[currentX - 1][currentY] == false)
				{											
					q.push(make_pair(currentX - 1, currentY));
					visit[currentX - 1][currentY] = visit[currentX][currentY] + 1;
				}
			}
		}
		// 하
		if (currentX + 1 <= N)
		{
			if (G[currentX + 1][currentY] == 1)
			{
				if (visit[currentX + 1][currentY] == false)
				{
					

					q.push(make_pair(currentX + 1, currentY));
					visit[currentX + 1][currentY] = visit[currentX][currentY] + 1;
					
				}
			}
		}
		// 좌
		if (currentY - 1 > 0)
		{
			if (G[currentX][currentY - 1] == 1)
			{
				if (visit[currentX][currentY - 1] == false)
				{
					q.push(make_pair(currentX, currentY - 1));
					visit[currentX][currentY - 1] = visit[currentX][currentY] + 1;
				}
			}
		}
		// 우
		if (currentY + 1 <= M)
		{
			if (G[currentX][currentY + 1] == 1)
			{
				if (visit[currentX][currentY + 1] == false)
				{
					q.push(make_pair(currentX, currentY + 1));
					visit[currentX][currentY + 1] = visit[currentX][currentY] + 1;
				}
			}
		}
	}
}

