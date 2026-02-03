#include <iostream>
#include <vector>

using namespace std;

int N, M;

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

vector<vector<int>> Gridmap;
vector<pair<int, int>> Rainmagic;
vector<pair<int, int>> Cloud;
vector<vector<bool>> Visit;

void Setup(){
    Gridmap.resize(N, vector<int>(N));
    Rainmagic.resize(M);
}

void Input(){
    
    cin >> N >> M;
    
    Setup();
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Gridmap[i][j];
        }
    }
    
    for(int i = 0; i < M; i++){
        cin >> Rainmagic[i].first >> Rainmagic[i].second;
    }
}

void Magic(){
    Cloud.push_back({N - 2, 0});
    Cloud.push_back({N - 2, 1});
    Cloud.push_back({N - 1, 0});
    Cloud.push_back({N - 1, 1});
}

void Simul(int d, int s){
    
    Visit.clear();
    Visit.resize(N, vector<bool>(N, false));
    
    for(size_t c = 0; c < Cloud.size(); c++){ // 1. 구름 이동
        Cloud[c] = {(Cloud[c].first + dx[d] * s + 30 * N) % N, (Cloud[c].second + dy[d] * s + 30 * N) % N};
    }
    for(pair<int, int> c : Cloud){ // 2. 비 내리기
        ++Gridmap[c.first][c.second];
        Visit[c.first][c.second] = true;
    }
    for(pair<int, int> c : Cloud){ // 4. 물 복사 버그 마법
        int cnt = 0;
        for(int i = 1; i < 8; i += 2){
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N && Gridmap[nx][ny] > 0) cnt++;
        }
        Gridmap[c.first][c.second] += cnt;
    } Cloud.clear(); // 3. 구름 없애기
    for(int i = 0; i < N; i++){ // 5. 구름 생기기
        for(int j = 0; j < N; j++){
            if(Gridmap[i][j] >= 2 && !Visit[i][j]){
                Gridmap[i][j] -= 2;
                Cloud.push_back({i, j});
            }
        }
    }
}

void Print(){
    int Ans = 0;
    // cout << "\n==========\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Ans += Gridmap[i][j];
            // cout << Gridmap[i][j] << " ";
        }
        // cout << "\n";
    } // cout << "\n==========\n";
    cout << Ans;
}

int main(){
    
    Input();
    
    Magic();
    
    for(pair<int, int> p : Rainmagic){
        Simul(p.first - 1, p.second);
    }
    
    Print();
    
    return 0;
}