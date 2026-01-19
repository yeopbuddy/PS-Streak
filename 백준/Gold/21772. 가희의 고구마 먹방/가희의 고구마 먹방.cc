#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int R, C, T;

int Ans = 0;

int dx[5] = {0,0,1,-1,0};
int dy[5] = {1,-1,0,0,0};

vector<vector<char>> Room;
vector<vector<bool>> Vis;

void Dfs(int x, int y, int sp, int cur, int lim){
    // cout << x << " " << y << "\n";
    Ans = max(Ans, sp);
    if(cur == lim){
        return;
    }
    for(int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < R && 0 <= ny && ny < C && Room[nx][ny] != '#'){
            if(Room[nx][ny] == 'S' && !Vis[nx][ny]){
                Vis[nx][ny] = true;
                Dfs(nx, ny, sp + 1, cur + 1, lim);
                Vis[nx][ny] = false;
            }else{
                Dfs(nx, ny, sp, cur + 1, lim);
            }
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> R >> C >> T;
    
    Vis.resize(R, vector<bool>(C, false));
    Room.resize(R, vector<char>(C));
    
    int Gx, Gy;
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> Room[i][j];
            if(Room[i][j] == 'G'){
               Gx = i; Gy = j; 
            }
        }
    }
    
    Dfs(Gx, Gy, 0, 0, T);
 
    cout << Ans;
    
    return 0;
}