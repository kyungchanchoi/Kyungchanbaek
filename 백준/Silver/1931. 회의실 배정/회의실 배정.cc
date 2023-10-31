#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 회의의 갯수  N ( 1 <= N <= 100,000)
	int N = 0;
	cin >> N;

	// 회의의 시작시간과 끝시간을 입력받고
	// vector에 회의의 시작시간과 걸리는 시간을 pair로 저장함
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start;
		cin >> end;

		v.push_back(make_pair(start, end));
	}

	// 시작시간 순으로 정렬
	sort(v.begin(), v.end());

	/*
	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}*/
	


	// 단순하게 생각해서 회의시간은 0부터 시작이다
	// 0부터 시작해서 현재 시작시간에 회의가능한 회의를 보고
	// 종료시간 이전에 시작하는 회의가 있다면 시간표에 안넣으면 된다

	
	int count = 1;
	int idx = 0;

	// 현재 회의
	int start = -1;
	int end = -1;
	bool exist = false;

	while (idx < N)
	{
		//cout << "idx :  " << idx << "   start : " << start << "   end : " << end << "    v[idx]의 첫번째 : " << v[idx].first << "   v[idx]의 두번째 : " << v[idx].second << "  count : " << count << "\n";
		
		if (start == -1)
		{
			// 첫 회의 입력
			start = v[idx].first;
			end = v[idx].second;

			idx++;
		}
		// 먼저 들어온 회의와 시작시간이 같을 때
		else if (v[idx].first == start)
		{
			// 더 일찍 끝나는 회의일 때
			if (end >= v[idx].second)
			{
				// 시작시간과 종료시간마저 같다면
				if (v[idx].second == start)
				{
					// 회의 확정, 카운트 추가
					count++;

					start = v[idx].first;
					end = v[idx].second;

					idx++;
				}
				// 그렇지는 않지만 종료시간이 더 빠르다면
				else
				{
					end = v[idx].second;

					idx++;
				}				
			}
			// 더 늦게 끝나는 회의라면
			else
			{
				// 혹시라도 이전 회의의 종료시간과 시작시간이 같다면
				if (v[idx].first >= end)
				{
					// 회의 확정, 카운트 추가
					count++;

					start = v[idx].first;
					end = v[idx].second;

					idx++;
				}
				else
				{
					idx++;
				}
				;
			}
		}
		// 먼저 들어온 회의보다 늦게 시작하는 회의라면
		else if (v[idx].first > start)
		{
			if (v[idx].first < end)
			{
				// 먼저 들어온 회의보다 일찍 끝난다면
				if (end >= v[idx].second)
				{
					start = v[idx].first;
					end = v[idx].second;

					idx++;
				}
				// 더 늦게 끝나는 회의면 넣을 수 없다
				else
				{
					idx++;
				}
			}			
			// 먼저 들어온 회의가 끝난 후에 시작하는 회의라면
			else 
			{
				// 회의 확정, 카운트 추가
				count++;

				start = v[idx].first;
				end = v[idx].second;

				idx++;
			}
		}
	}

	cout << count;
	
	return 0;
}