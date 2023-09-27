#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MergeSort(vector<int>& v, vector<int>& temp, int left, int right);
void Merge(vector<int>& v, vector<int>& temp, int left, int right);
int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	int num = 0;
	vector<int> v;
	vector<int> temp;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		temp.push_back(num);
	}

	// Merge Sort : 재귀적으로 나눌수 없을때까지 나누고(Divde), 다 나눴으면 정렬하며 병합한다(Conquer)
	MergeSort(v, temp, 0, N - 1);

	// 출력
	for (int i = 0; i < N; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}
void MergeSort(vector<int>& v, vector<int>& temp, int left, int right)
{	
	// 나눌수 없을때까지 나눈다 = left가 right보다 같아지기 전까지 재귀함수 호출
	if (left < right)
	{
		int mid = (right + left) / 2;

		MergeSort(v, temp, left, mid);
		MergeSort(v, temp, mid + 1, right);

		// 다 나눴을때부터는 Merge가 시작된다
		Merge(v, temp, left, right);
	}
}
void Merge(vector<int>& v, vector<int>&  temp, int left, int right)
{		
	int leftidx = left; // 왼쪽 그룹 시작 인덱스
	int mid = (right + left) / 2; // 중간
	int rightidx = mid + 1; // 오른쪽 그룹 시작 인덱스
	int currentidx = left; // 실제 배열에 넣기 위한 인덱스

	for (int i = left; i <= right; i++)
	{
		temp[i] = v[i];
	}

	while (leftidx <= mid && rightidx <= right)
	{
		if (temp[leftidx] < temp[rightidx])
		{
			v[currentidx] = temp[leftidx];
			leftidx++;
		}
		else
		{
			v[currentidx] = temp[rightidx];
			rightidx++;
		}

		currentidx++;
	}
	
	// 다 끝났을 때 왼쪽 그룹의 값이 남아있다면
	if (leftidx <= mid)
	{
		for (int i = leftidx; i <= mid; i++)
		{
			v[currentidx] = temp[i];
			currentidx++;
		}
	}
}