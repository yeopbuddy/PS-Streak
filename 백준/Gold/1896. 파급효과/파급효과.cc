#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int T, R, C;

	cin >> T;

	for (int t = 0; t < T; t++) {
		
		// Init Process
		cin >> R >> C;

		vector<vector<char>> Grid (R, vector<char>(C));
		vector<vector<int>> Polynomio (R, vector<int>(C));
		vector<vector<bool>> Visit (R, vector<bool>(C, false));

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> Grid[r][c];
			}
		}

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> Polynomio[r][c];
			}
		}
		
		// Valid Check Process : Rule 1 - 1 ~ (폴리노미오 안의 칸 수) 의 자연수들은 해당 폴리노미오 안에 반드시 한번씩만 배치되어야 한다.
		bool fail1 = false;

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (!Visit[r][c]) {
					Visit[r][c] = true;
					
					vector<pair<int, int>> Mini;
					vector<pair<int, int>> Vec;

					Mini.push_back({ r, c });
					Vec.push_back({ r, c });

					while (!Vec.empty()) {
						
						int px = Vec[Vec.size() - 1].first;
						int py = Vec[Vec.size() - 1].second;
						
						Vec.pop_back();
						
						if (Polynomio[px][py] >= 8) {
							Polynomio[px][py] -= 8;
							if (!Visit[px][py - 1]) {
								Vec.push_back({ px, py - 1 });
								Mini.push_back({ px, py - 1 });
							}
							Visit[px][py - 1] = true;
						}
						if (Polynomio[px][py] >= 4) {
							Polynomio[px][py] -= 4;
							if (!Visit[px + 1][py]) {
								Vec.push_back({ px + 1, py });
								Mini.push_back({ px + 1, py });
							}
							Visit[px + 1][py] = true;
						}
						if (Polynomio[px][py] >= 2) {
							Polynomio[px][py] -= 2;
							if (!Visit[px][py + 1]) {
								Vec.push_back({ px, py + 1 });
								Mini.push_back({ px, py + 1 });
							}
							Visit[px][py + 1] = true;
						}
						if (Polynomio[px][py] >= 1) {
							Polynomio[px][py] -= 1;
							if (!Visit[px - 1][py]) {
								Vec.push_back({ px - 1, py });
								Mini.push_back({ px - 1, py });
							}
							Visit[px - 1][py] = true;
						}
					}

					vector<bool> MiniV(Mini.size(), false); // 판단
					for (pair<int, int> p : Mini) {
						int G = Grid[p.first][p.second] - '1';
						if ((G < 0 || G >= Mini.size()) || MiniV[G]) fail1 = true;
						MiniV[G] = true;
					}
					
				}
			}
		}

		// Valid Check Process : Rule 2 - 하나의 줄이나 행에 동일한 숫자가 배치되기 위해선 두 숫자 사이에 해당 숫자만큼의 다른 칸이 존재해야 한다
		bool fail2 = false;

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				
				int a = Grid[r][c] - '0';
				
				int sr = (0 > r - a ? 0 : r - a);
				int er = (R <= r + a ? R - 1 : r + a);
				int sc = (0 > c - a ? 0 : c - a);
				int ec = (C <= c + a ? C - 1 : c + a);

				for (int x = sr; x <= er; x++) { // 판단
					if (x == r) continue;
					if (Grid[x][c] == Grid[r][c]) {
						fail2 = true;
					}
				}

				for (int y = sc; y <= ec; y++) { // 판단
					if (y == c) continue;
					if (Grid[r][y] == Grid[r][c]) {
						fail2 = true;
					}
				}
			}
		}

		
		cout << ((fail1 || fail2) ? "invalid\n" : "valid\n");

		// Clear Process
		Grid.clear();
		Polynomio.clear();
	}

}