#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> &A, int n);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 자연수 N(1 ≤ N ≤ 100,000)
	int N = 0;
	cin >> N;

	vector<int> A;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}

	// A를 오름차순 정렬
	sort(A.begin(), A.end());

	// M(1 ≤ M ≤ 100,000)
	int M = 0;
	cin >> M;

	//cout << binary_search(A, M) << "\n";

	
	for (int i = 0; i < M; i++)
	{
		int check;
		cin >> check;

		cout << binary_search(A, check) << "\n";
	}


	return 0;
}
int binary_search(vector<int> &A, int n)
{
	// 중앙값의 인덱스를 구한다
	int fullsize = A.size();

	int start = 0;
	int end = fullsize - 1;
	int mid = (start + end) / 2;

	
	while ( fullsize > 0 )
	{
		//cout << "현재 fullsize : " << fullsize << "  ";
		//cout << "찾는값  : " << n << "   중앙값 : " << A[mid] << "\n";
			
		// 타깃데이터 < 중앙값
		if (n < A[mid])
		{
			// 왼쪽 data set으로 이동
			end = mid - 1;
			mid =  (start + end) / 2;
		}
		// 타깃데이터 > 중앙값
		else if (n > A[mid])
		{
			// 오른쪽 data set으로 이동
			start = mid + 1;
			mid = (start + end) / 2;
		}
		// 타깃데이터 = 중앙값
		else if (n == A[mid])
		{
			return 1; // 존재하므로 1 리턴
		}

		fullsize /= 2;
	}

	return 0;
}