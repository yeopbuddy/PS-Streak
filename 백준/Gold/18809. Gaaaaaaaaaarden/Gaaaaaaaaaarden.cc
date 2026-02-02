#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, G, R, Ans = 0;
int Garden[51][51];
pair<int, int> Dist[51][51]; // first: 시간, second: 상태(0:빈칸, 1:G, 2:R, 3:꽃)
vector<pair<int, int>> Grass, Green, Red;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void Solve() {
    int flw = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) Dist[i][j] = {-1, 0};

    queue<pair<int, int>> q;

    for (auto p : Green) {
        Dist[p.first][p.second] = {0, 1};
        q.push(p);
    }
    for (auto p : Red) {
        Dist[p.first][p.second] = {0, 2};
        q.push(p);
    }

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (Dist[cx][cy].second == 3) continue; // 이미 꽃이 된 자리는 확산 불가

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (Garden[nx][ny] == 0) continue; // 호수 제외

            // 1. 아직 아무도 안 온 땅
            if (Dist[nx][ny].first == -1) {
                Dist[nx][ny] = {Dist[cx][cy].first + 1, Dist[cx][cy].second};
                q.push({nx, ny});
            }
            // 2. 이미 누가 온 땅인데, 꽃이 필 수 있는지 확인
            else if (Dist[nx][ny].second != 3) {
                // 다른 색깔 배양액이 동시에 도달했을 때
                if (Dist[nx][ny].second != Dist[cx][cy].second && 
                    Dist[nx][ny].first == Dist[cx][cy].first + 1) {
                    Dist[nx][ny].second = 3;
                    flw++;
                }
            }
        }
    }
    Ans = (Ans > flw) ? Ans : flw;
}

void Select(int g, int r, int s){
    if(g == G && r == R){
        // cout << "\n=====G=====\n";
        // for(pair<int, int> p : Green){
        //     cout << p.first << " " << p.second << "\n";
        // } cout << "\n=====R=====\n";
        // for(pair<int, int> p : Red){
        //     cout << p.first << " " << p.second << "\n";
        // }
        // Green과 Red를 활용해 Flower의 개수 구하기
        Solve();
        return;
    }
    
    if(s < Grass.size()){
        if(g < G){
            Green.push_back(Grass[s]);
            Select(g + 1, r, s + 1);
            Green.pop_back();
        }
        if(r < R){
            Red.push_back(Grass[s]);
            Select(g, r + 1, s + 1);
            Red.pop_back();
        }
        if(G - g + R - r < Grass.size() - s) Select(g, r, s + 1);
    }   
}

void Input(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> N >> M >> G >> R;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Garden[i][j];
            if(Garden[i][j] == 2) Grass.push_back({i, j});
        }
    }
}

int main(){
    
    Input();
    
    Select(0, 0, 0);
    
    cout << Ans;
    
    return 0;
}