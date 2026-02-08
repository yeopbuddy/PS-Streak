#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

// 동적 배열 없이 해보기!

int Arr[101][101];
int Vis[101][101][4];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
// turn right: + 1 % 4, turn left: + 3 % 4

int main(){
    
    int N, M;

    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Arr[i][j];
            for(int k = 0; k < 4; k++){
                Vis[i][j][k] = 1e9;
            }
        }
    }

    int Stx, Sty, Std, Edx, Edy, Edd;

    cin >> Stx >> Sty >> Std >> Edx >> Edy >> Edd;
    --Stx; --Sty; --Std; --Edx; --Edy; --Edd; // 0-base
    
    if(Std == 1 || Std == 2){ // 남<-> 서 스위칭
        Std %= 2; Std++;
    }
    if(Edd == 1 || Edd == 2){
        Edd %= 2; Edd++;
    }
    deque<tuple<int, int, int>> dq;
    dq.push_back({Stx, Sty, Std});
    Vis[Stx][Sty][Std] = 0;

    while(!dq.empty()){
        int px, py, pd;
        tie(px, py, pd) = dq.front();
        dq.pop_front();
        
        if(px == Edx && py == Edy && pd == Edd){
            cout << Vis[px][py][pd];
            return 0;
        }
        
        int nd1 = (pd + 1) % 4;
        if(Vis[px][py][pd] + 1 < Vis[px][py][nd1]){ // 우회전
            Vis[px][py][nd1] = Vis[px][py][pd] + 1;
            dq.push_back({px, py, nd1});
        }
        
        int nd2 = (pd + 3) % 4;
        if(Vis[px][py][pd] + 1 < Vis[px][py][nd2]){ // 좌회전
            Vis[px][py][nd2] = Vis[px][py][pd] + 1;
            dq.push_back({px, py, nd2});
        }
        for(int i = 1; i <= 3; i++){
            int nx = px + dx[pd] * i;
            int ny = py + dy[pd] * i;
            if(Arr[nx][ny] == 1) break;
            if(0 <= nx && nx < N && 0 <= ny && ny < M && Vis[nx][ny][pd] > Vis[px][py][pd] + 1){ // 이동
                Vis[nx][ny][pd] = Vis[px][py][pd] + 1;
                dq.push_back({nx, ny, pd});
            }   
        }
    }
}