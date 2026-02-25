#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

int main(){
    
    int n, m;
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    while(cin >> m >> n){
        
        if(n == 0 && m == 0) break;
        
        vector<vector<char>> dungeon(n, vector<char>(m));
        vector<vector<vector<int>>> visit(n, vector<vector<int>>(m, vector<int>(256, 1e9)));
        vector<int> alpas(26, 0);
        
        int sx, sy, fx, fy;
        int aval = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> dungeon[i][j];
                if(dungeon[i][j] == '@'){
                    sx = i; sy = j;
                }else if(dungeon[i][j] == '<'){
                    fx = i; fy = j;
                }else if('A' <= dungeon[i][j] && dungeon[i][j] <= 'Z' && alpas[dungeon[i][j] - 'A'] == 0){
                    alpas[dungeon[i][j] - 'A'] = aval; aval *= 2; // alphabet mapping(bit)
                }
            }
        }
        
        deque<tuple<int, int, int, int>> dq; // x, y, dist, status
        dq.push_back({sx, sy, 0, 0});
        visit[sx][sy][0] = 0;
        
        bool clear = false;
        
        while(!dq.empty()){
            
            int px, py, pd, ps;
            tie(px, py, pd, ps) = dq.front();
            
            dq.pop_front();
            
            if(px == fx && py == fy){
                cout << visit[px][py][ps] << "\n";
                clear = true;
                break;
            }
            
            for(int i = 0; i < 4; i++){
                int nx = px + dx[i];
                int ny = py + dy[i];
                int nd = pd + 1;
                if(0 <= nx && nx < n && 0 <= ny && ny < m && dungeon[nx][ny] != '#'){
                    if((dungeon[nx][ny] == '.' || dungeon[nx][ny] == '<' || dungeon[nx][ny] == '@') && (visit[nx][ny][ps] > nd)){ // status change x
                        visit[nx][ny][ps] = nd;
                        dq.push_back({nx, ny, nd, ps});
                    }else if('a' <= dungeon[nx][ny] && dungeon[nx][ny] <= 'z'){ // status change
                        int ns = ps ^ alpas[dungeon[nx][ny] - 'a'];
                        if(visit[nx][ny][ns] > nd){
                            visit[nx][ny][ns] = nd;
                            dq.push_back({nx, ny, nd, ns});
                        }
                    }else if('A' <= dungeon[nx][ny] && dungeon[nx][ny] <= 'Z' && visit[nx][ny][ps] > nd){ // depends on status
                        int open = ps & alpas[dungeon[nx][ny] - 'A'];
                        if(open == alpas[dungeon[nx][ny] - 'A']){
                            visit[nx][ny][ps] = nd;
                            dq.push_back({nx, ny, nd, ps});
                        }
                    }
                }
            }
        }
        
        if(!clear) cout << -1 << "\n";
    }

    return 0;
}