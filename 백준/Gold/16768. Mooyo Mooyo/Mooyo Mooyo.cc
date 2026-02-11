#include <iostream>
#include <deque>

using namespace std;

int N, K;

char MooyoMooyo[100][10];

void Simulate(){
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    while(true){
        bool change = false;
        bool visit[100][10];
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 10; j++){
                visit[i][j] = false;
            }
        }    
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 10; j++){
                if(MooyoMooyo[i][j] != '0' && !visit[i][j]){
                    visit[i][j] = true;
                    deque<pair<int, int>> dq;
                    deque<pair<int, int>> cache;
                    dq.push_back({i, j});
                    cache.push_back({i, j});
                    while(!dq.empty()){
                        int px = dq.front().first;
                        int py = dq.front().second;
                        dq.pop_front();
                        for(int k = 0; k < 4; k++){
                            int nx = px + dx[k];
                            int ny = py + dy[k];
                            if(0 <= nx && nx < N && 0 <= ny && ny < 10 && MooyoMooyo[nx][ny] == MooyoMooyo[i][j] && !visit[nx][ny]){
                                visit[nx][ny] = true;
                                dq.push_back({nx, ny});
                                cache.push_back({nx, ny});
                            }
                        }
                    }
                    if(cache.size() >= K){
                        change = true;
                        for(pair<int, int> p : cache){
                            MooyoMooyo[p.first][p.second] = '0';
                        }
                    }
                }
            }
        }
        
        if(!change) break;
        
        for(int j = 0; j < 10; j++){
            deque<char> dq;
            for(int i = N - 1; i >= 0; i--){
                if(MooyoMooyo[i][j] != '0') dq.push_back(MooyoMooyo[i][j]);
            }
            if(!dq.empty()){
                for(int i = N - 1; i >= 0; i--){
                    if(!dq.empty()){
                        MooyoMooyo[i][j] = dq.front(); dq.pop_front();
                    } else MooyoMooyo[i][j] = '0';
                }   
            }
        }
    }
}

int main(){
    
    cin >> N >> K;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            cin >> MooyoMooyo[i][j];
        }
    }
    
    Simulate();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            cout << MooyoMooyo[i][j];
        }
        cout << "\n";
    }

    return 0;
}