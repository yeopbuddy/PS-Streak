#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, M;
	cin >> N >> M;

	vector<vector<int>> RightUp(N, vector<int>(M));
	vector<vector<int>> RightDown(N, vector<int>(M));

	for(int n = 0; n < N; n++)
	{
		for(int m = 0; m < M; m++)
		{
			cin >> RightUp[n][m];

			RightDown[n][m] = RightUp[n][m];
		}
	}

	for(int n = N - 2; n >= 0; n--)
	{
		RightUp[n][0] += RightUp[n + 1][0];
		RightDown[n][M - 1] += RightDown[n + 1][M - 1];
	}

	for(int m = 1; m < M; m++)
	{
		RightUp[N - 1][m] += RightUp[N - 1][m - 1];
		RightDown[N - 1][M - 1 - m] += RightDown[N - 1][M - m];
	}

	for(int m = 1; m < M; m++)
	{
		for(int n = N - 2; n >= 0; n--)
		{
			RightUp[n][m] += max(RightUp[n + 1][m], RightUp[n][m - 1]);
			RightDown[n][M - 1 - m] += max(RightDown[n + 1][M - 1 - m], RightDown[n][M - m]);
		}
	}

    int ans = -100000000;

    for(int n = 0; n < N; n++)
	{
		for(int m = 0; m < M; m++)
		{
			ans = max(ans, RightUp[n][m] + RightDown[n][m]);
		}
	}
	
	cout << ans;

	return 0;
}