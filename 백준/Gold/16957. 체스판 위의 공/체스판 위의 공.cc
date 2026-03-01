#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int R, C;
    
    cin >> R >> C;
    
    vector<vector<int>> chessboard(R, vector<int>(C));
    vector<vector<int>> Ans(R, vector<int>(C, 0));
    vector<vector<pair<int, int>>> Sol(R, vector<pair<int, int>>(C));
    vector<vector<int>> vis(R, vector<int>(C, 1));
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> chessboard[i][j];
        }
    }

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(vis[i][j]){
                vis[i][j] = 0;
                vector<pair<int, int>> tmp;
                tmp.push_back({i, j});
                int x = i;
                int y = j;
                while(true){
                    int nx = -1;
                    int ny = -1;
                    int nval = 300001;
                    for(int k = 0; k < 8; k++){
                        int px = x + dx[k];
                        int py = y + dy[k];
                        if(0 <= px && px < R && 0 <= py && py < C && chessboard[x][y] > chessboard[px][py] && chessboard[px][py] < nval){
                            nval = chessboard[px][py]; nx = px; ny = py;
                        }
                    }
                    if(nx == -1 && ny == -1){
                        for(pair<int, int> p : tmp) Sol[p.first][p.second] = {x, y};
                        break;
                    }
                    x = nx; y = ny;
                    if(!vis[x][y]){
                        for(pair<int, int> p : tmp) Sol[p.first][p.second] = Sol[x][y];
                        break;
                    }tmp.push_back({x, y});
                    vis[x][y] = 0;
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            Ans[Sol[i][j].first][Sol[i][j].second]++;
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << Ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}