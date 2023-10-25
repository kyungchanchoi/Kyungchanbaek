#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	// 코딩테스트용 스트림 해제 코드
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1 ≤ X ≤ 1,000,000,000
	int X = 0;
	cin >> X; // 형택이가 진행한 게임수

	// 0 ≤ Y ≤ X
	int Y = 0;
	cin >> Y; // 형택이새끼가 이긴 횟수

	long long Z = (long long)Y * 100 / X;

	//cout << X << " " << Y << " " << Z;

	// 앞으로는 계속 이기므로 X와 Y값이 동등하게 올라간다
	// 다만 그 값이 너무 크므로 1씩 증가시키다간 지구가 멸망함

	// 따라서 임의의 판수를 정한다음
	// 그 판만큼 했을 때 Z값이 바뀌면 임시 저장하고 판수를 줄여보고
	// 안바뀌면 판수를 늘려보는 이분탐색을 해본다
	int start = 1; // 최소 한판은 해야한다
	int end = X; // 여태까지 한 게임횟수를 최대로 잡는다

	long result = 0; // 바뀌었을 때의 값 저장

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int calX = X;
		int calY = Y;

		calX += mid;
		calY += mid;

		long long calZ = (long long)calY * 100 / calX;

		//cout << "start는 " << start << "  end는 " << end << "  mid는 " << mid << "   Z와 calZ는 각각 " << Z << " " << calZ << "\n";
		// 안 바뀌었으면
		if (calZ <= Z)
		{
			start = mid + 1;
		}

		// 바뀌었으면 값 임시저장하고 판수를 줄여본다(최솟값찾기이므로)
		else
		{
			if (result == 0) result = mid;
			else
			{
				if (result > mid) result = mid;
			}
			end = mid - 1;
		}
	}

	if (result == 0) cout << "-1";
	else cout << result;


	return 0;
}
