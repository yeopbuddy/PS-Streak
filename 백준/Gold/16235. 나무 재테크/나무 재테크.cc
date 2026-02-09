#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, K;

int Feed[11][11]; 
int Curr[11][11]; 

deque<int> Tree[11][11]; 

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Feed[i][j];
            Curr[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Tree[x][y].push_back(z);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sort(Tree[i][j].begin(), Tree[i][j].end());
        }
    }

    while (K--) {
        // 봄 & 여름
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                deque<int> alive;
                int dead_feed = 0;
                for (int age : Tree[i][j]) {
                    if (Curr[i][j] >= age) {
                        Curr[i][j] -= age;
                        alive.push_back(age + 1);
                    } else {
                        dead_feed += age / 2;
                    }
                }
                Tree[i][j] = alive;
                Curr[i][j] += dead_feed;
            }
        }

        // 가을 & 겨울
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int age : Tree[i][j]) { // 가을
                    if (age % 5 == 0) {
                        for (int d = 0; d < 8; d++) {
                            int nx = i + dx[d], ny = j + dy[d];
                            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                                Tree[nx][ny].push_front(1);
                            }
                        }
                    }
                }
                Curr[i][j] += Feed[i][j]; // 겨울
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += Tree[i][j].size();
        }
    }
    cout << ans;

    return 0;
}