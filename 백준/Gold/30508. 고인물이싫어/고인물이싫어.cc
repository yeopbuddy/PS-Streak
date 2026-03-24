#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	
	int N, M, H, W, K;

	cin >> N >> M >> H >> W;

	vector<vector<int>> Crosswalk(N, vector<int>(M));
	vector<vector<bool>> Visit(N, vector<bool>(M, false));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> Crosswalk[n][m];
		}
	}
	
	cin >> K;

	deque<pair<int, int>> dq(K);

	for (int k = 0; k < K; k++) {
		cin >> dq[k].first >> dq[k].second;
		dq[k] = { --dq[k].first, --dq[k].second };
		Visit[dq[k].first][dq[k].second] = true;
	}

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	while (!dq.empty()) {
		
		int px = dq.front().first;
		int py = dq.front().second;
		dq.pop_front();
		
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !Visit[nx][ny] && Crosswalk[nx][ny] >= Crosswalk[px][py]) {
				dq.push_back({ nx, ny });
				Visit[nx][ny] = true;
			}
		}
	}

	int ans = 0;

	Crosswalk.clear();
	Crosswalk.resize(N, vector<int>(M, 0));

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			Crosswalk[n][m] = (!Visit[n][m] ? 1 : 0);
		}
	}

	for (int n = 1; n < N; n++) {	
		Crosswalk[n][0] += Crosswalk[n - 1][0];
	}

	for (int m = 1; m < M; m++) {
		Crosswalk[0][m] += Crosswalk[0][m - 1];
	}
	
	for (int n = 1; n < N; n++) {
		for (int m = 1; m < M; m++) {
			Crosswalk[n][m] += (Crosswalk[n - 1][m] + Crosswalk[n][m - 1] - Crosswalk[n - 1][m - 1]);
		}
	}

	for (int n = H - 1; n < N; n++) {
		for (int m = W - 1; m < M; m++) {
			int r1 = n - H + 1, c1 = m - W + 1;
			int sum = Crosswalk[n][m];
			if (r1 > 0) sum -= Crosswalk[r1 - 1][m];
			if (c1 > 0) sum -= Crosswalk[n][c1 - 1];
			if (r1 > 0 && c1 > 0) sum += Crosswalk[r1 - 1][c1 - 1];

			if (sum == 0) ans++;
		}
	}

	cout << ans;
}
