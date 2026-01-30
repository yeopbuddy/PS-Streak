// 언제쓸지모르는스트릭
// https://www.acmicpc.net/problem/2589

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
    
    int Ans = 0;
    
    int L, W;
    cin >> L >> W;
    
    vector<vector<char>> Map(L, vector<char>(W));
    vector<vector<bool>> Visit(L, vector<bool>(W, false));
    
    for(int i = 0; i < L; i++){
        for(int j = 0; j < W; j++){
            cin >> Map[i][j];
        }
    }


    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    for(int i = 0; i < L; i++){
        for(int j = 0; j < W; j++){
            if(Map[i][j] == 'L' && !Visit[i][j]){
                vector<pair<int, int>> Coords;
                deque<pair<int, int>> dq1;
                dq1.push_back({i, j});
                Coords.push_back({i, j});
                Visit[i][j] = true;
                while(!dq1.empty()){
                    int px = dq1.front().first;
                    int py = dq1.front().second;
                    dq1.pop_front();
                    for(int k = 0; k < 4; k++){
                        int nx = px + dx[k];
                        int ny = py + dy[k];
                        if(0 <= nx && nx < L && 0 <= ny && ny < W && Map[nx][ny] == 'L' && !Visit[nx][ny]){
                            Coords.push_back({nx, ny});
                            dq1.push_back({nx, ny});
                            Visit[nx][ny] = true;
                        }
                    }
                }
                // cout << "=====\n";
                // for(pair<int, int> p : Coords){
                //     cout << p.first << " " << p.second << "\n";
                // }
                // cout << "=====\n";
                for(pair<int, int> p1 : Coords){
                    for(pair<int, int> p2 : Coords){
                        Visit[p2.first][p2.second] = false;   
                    }
                    deque<tuple<int, int, int>> dq2;
                    dq2.push_back({p1.first, p1.second, 0});
                    Visit[p1.first][p1.second] = true;
                    while(!dq2.empty()){
                        int px, py, pd;
                        tie(px, py, pd) = dq2.front();
                        dq2.pop_front();
                        for(int k = 0; k < 4; k++){
                            int nx = px + dx[k];
                            int ny = py + dy[k];
                            if(0 <= nx && nx < L && 0 <= ny && ny < W && Map[nx][ny] == 'L' && !Visit[nx][ny]){
                                dq2.push_back({nx, ny, pd + 1});
                                Ans = max(Ans, pd + 1);
                                Visit[nx][ny] = true;
                            }
                        }
                    }
                }
                for(pair<int, int> p2 : Coords){
                    Visit[p2.first][p2.second] = true;   
                }
            }
        }
    }
    
    cout << Ans;
    return 0;
}
