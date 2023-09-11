#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;


class Node
{
public:
	int idx = 0;
	int data = 0;
};
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, L = 0;

	cin >> N >> L;

	deque<Node> d;
	int num = 0; // A0, A1, ... , An
	Node *t = new Node();
	
	vector<int> result;

	for (int i = 0; i < N; i++) // 1부터 N까지의 인덱스를 사용한다

	{
		cin >> num;

		t->idx = i+1;
		t->data = num;

		// 최솟값 확인
		// 첫 값이라면
		if (i == 0)
		{
			d.push_back(*t); // 덱에 넣어주고
			result.push_back(num); // 최솟값도 그값이므로 넣어준다
		}

		// 두번째 값부터는
		else
		{
			if (i+1 - d.front().idx >= L) d.pop_front(); // 현재 i에서 가장 맨앞 인덱스 frontidx의 차이가 L보다 같거나 크면 맨앞 노드를 빼준다
			
			// 새로 입력받은 데이터 노드 t에 대하여
			while (d.empty() != true)
			{
				if (d.back().data > num) // 현재 입력받은 값이 이전 값보다 작다면
				{
					d.pop_back(); // 가장 맨 뒤에 있는 노드를 지운다
				}

				else break;
			} // 덱의 텅텅 빌때까지

			d.push_back(*t); // 덱에 최신값을 넣어주고
			result.push_back(d.front().data); // 최솟값은 가장 맨 앞의 데이터값이므로 넣어준다
		}

	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}
