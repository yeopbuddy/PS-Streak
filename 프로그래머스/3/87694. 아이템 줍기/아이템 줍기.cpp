#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    const int N = 102;
    
    characterX *= 2; characterY *= 2;
    itemX *= 2;      itemY *= 2;
    
    // 0: 미지, 1: 테두리, 2: 내부
    vector<vector<int>> map(N, vector<int>(N, 0));
    
    for (auto& r : rectangle) {
        int x1 = r[0]*2, y1 = r[1]*2, x2 = r[2]*2, y2 = r[3]*2;
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                if (map[x][y] == 2) continue;
                bool onEdge = (x == x1 || x == x2 || y == y1 || y == y2);
                if (onEdge) {
                    if (map[x][y] == 0) map[x][y] = 1;
                } else {
                    map[x][y] = 2;
                }
            }
        }
    }
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int,int>> q;
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == itemX && y == itemY) return dist[x][y] / 2;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (map[nx][ny] != 1) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}